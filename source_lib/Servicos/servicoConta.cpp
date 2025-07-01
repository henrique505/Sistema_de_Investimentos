#include "servicoConta.hpp"

ServicoConta::ServicoConta() {
    conectar();
    criarTabela();
}

ServicoConta::~ServicoConta() {
    desconectar();
}

void ServicoConta::conectar() {
    sqlite3_open("Data/usuarios.db", &db);
}

void ServicoConta::desconectar() {
    if (db) sqlite3_close(db);
}

void ServicoConta::criarTabela() {
    const char *sql = "CREATE TABLE IF NOT EXISTS usuarios (cpf TEXT PRIMARY KEY, "
                      "senha TEXT NOT NULL, nome TEXT NOT NULL);";

    char *errMsg = nullptr;
    sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
    if (errMsg) {
        std::cerr << "Erro ao criar tabela contas: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool ServicoConta::criar(const Conta &conta) {
    const char *sql = "INSERT INTO usuarios (cpf, senha, nome) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) return false;

    sqlite3_bind_text(stmt, 1, conta.getCpf().getCPF().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, conta.getSenha().getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, conta.getNome().getNome().c_str(), -1, SQLITE_STATIC);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

Conta ServicoConta::ler(const CPF &cpf) {
    Conta conta;
    const char *sql = "SELECT nome, senha FROM usuarios WHERE cpf = ?;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string nomeStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            std::string senhaStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

            try {
                Nome nome;
                nome.setNome(nomeStr);
                conta.setNome(nome);

                Senha senha;
                senha.setSenha(senhaStr);
                conta.setSenha(senha);

                conta.setCpf(cpf);
            } catch (std::invalid_argument &e) {
                std::cerr << "Erro ao ler conta: " << e.what() << std::endl;
            }
        }
    }

    sqlite3_finalize(stmt);
    return conta;
}

bool ServicoConta::editar(const Conta &conta) {
    Conta contaAtual = ler(conta.getCpf());  // Busca dados atuais

    Conta contaFinal;
    contaFinal.setCpf(conta.getCpf());

    // Nome
    try {
        if (!conta.getNome().getNome().empty()) {
            contaFinal.setNome(conta.getNome());
        } else {
            contaFinal.setNome(contaAtual.getNome());
        }
    } catch (...) {
        contaFinal.setNome(contaAtual.getNome());
    }

    // Senha
    try {
        if (!conta.getSenha().getSenha().empty()) {
            contaFinal.setSenha(conta.getSenha());
        } else {
            contaFinal.setSenha(contaAtual.getSenha());
        }
    } catch (...) {
        contaFinal.setSenha(contaAtual.getSenha());
    }

    const char *sql = "UPDATE usuarios SET nome = ?, senha = ? WHERE cpf = ?;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, contaFinal.getNome().getNome().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, contaFinal.getSenha().getSenha().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, contaFinal.getCpf().getCPF().c_str(), -1, SQLITE_STATIC);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

bool ServicoConta::excluir(const CPF &cpf) {
    const char *sql = "DELETE FROM usuarios WHERE cpf = ?;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        std::cerr << "Erro ao preparar DELETE: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }

    sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);

    int resultado = sqlite3_step(stmt);
    bool sucesso = (resultado == SQLITE_DONE && sqlite3_changes(db) > 0);

    if (!sucesso) {
        std::cerr << "Falha ao excluir conta ou CPF inexistente.\n";
    }

    sqlite3_finalize(stmt);
    return sucesso;
}
