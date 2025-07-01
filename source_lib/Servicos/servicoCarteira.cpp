//
// Created by Henrique on 29/06/2025.
//
#include "servicoCarteira.hpp"

ServicoCarteira::ServicoCarteira() {
    conectar();
    criarTabela();
    desconectar();
}

ServicoCarteira::~ServicoCarteira() {
    desconectar();
}

void ServicoCarteira::conectar() {
    sqlite3_open("Data/carteiras.db", &db);
}

void ServicoCarteira::desconectar() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void ServicoCarteira::criarTabela() {
    const char *sql = "CREATE TABLE IF NOT EXISTS carteiras ("
                      "codigo TEXT PRIMARY KEY,"
                      "nome TEXT NOT NULL,"
                      "perfil TEXT NOT NULL,"
                      "cpf TEXT NOT NULL);"; // cpf é apenas persistido
    char *errMsg = nullptr;
    sqlite3_exec(db, sql, nullptr, nullptr, &errMsg);
    if (errMsg) {
        std::cerr << "Erro ao criar tabela carteiras: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool ServicoCarteira::criarCarteiraPara(const CPF &cpf, const Carteira &carteira) {
    conectar();

    // Verificar limite de 5 carteiras por CPF
    const char *contar = "SELECT COUNT(*) FROM carteiras WHERE cpf = ?;";
    sqlite3_stmt *stmt;
    int total = 0;

    if (sqlite3_prepare_v2(db, contar, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            total = sqlite3_column_int(stmt, 0);
        }
    }
    sqlite3_finalize(stmt);

    if (total >= 5) {
        desconectar();
        throw DominioException("Limite de 5 carteiras atingido para este CPF.");
    }

    // Inserir carteira
    const char *sql = "INSERT INTO carteiras (codigo, nome, perfil, cpf) VALUES (?, ?, ?, ?);";
    bool sucesso = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, carteira.getCodigo().getCodigo().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, carteira.getNome().getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, carteira.getPerfil().getPerfil().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, cpf.getCPF().c_str(), -1, SQLITE_STATIC);

        sucesso = sqlite3_step(stmt) == SQLITE_DONE;
    }

    sqlite3_finalize(stmt);
    desconectar();
    return sucesso;
}

std::list<Carteira> ServicoCarteira::listarCarteirasPor(const CPF &cpf) {
    conectar();
    const char *sql = "SELECT codigo, nome, perfil FROM carteiras WHERE cpf = ?;";
    sqlite3_stmt *stmt;
    std::list<Carteira> lista;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string codStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            std::string nomeStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));
            std::string perfilStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2));

            Codigo codigo; codigo.setCodigo(codStr);
            Nome nome; nome.setNome(nomeStr);
            Perfil perfil; perfil.setPerfil(perfilStr);

            Carteira carteira;
            carteira.setCodigo(codigo);
            carteira.setNome(nome);
            carteira.setPerfil(perfil);

            lista.push_back(carteira);
        }
    }

    sqlite3_finalize(stmt);
    desconectar();
    return lista;
}

Carteira ServicoCarteira::ler(const Codigo &codigo) {
    conectar();

    const char *sql = "SELECT nome, perfil FROM carteiras WHERE codigo = ?;";
    sqlite3_stmt *stmt;
    Carteira carteira;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_STATIC);
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            std::string nomeStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0));
            std::string perfilStr = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

            Nome nome; nome.setNome(nomeStr);
            Perfil perfil; perfil.setPerfil(perfilStr);

            carteira.setCodigo(codigo);
            carteira.setNome(nome);
            carteira.setPerfil(perfil);
        }
    }

    sqlite3_finalize(stmt);
    desconectar();
    return carteira;
}

bool ServicoCarteira::editar(const Carteira &carteira) {
    conectar();
    const char *sql = "UPDATE carteiras SET nome = ?, perfil = ? WHERE codigo = ?;";
    sqlite3_stmt *stmt;
    bool sucesso = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, carteira.getNome().getNome().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, carteira.getPerfil().getPerfil().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, carteira.getCodigo().getCodigo().c_str(), -1, SQLITE_STATIC);

        sucesso = sqlite3_step(stmt) == SQLITE_DONE;
    }

    sqlite3_finalize(stmt);
    desconectar();
    return sucesso;
}

bool ServicoCarteira::excluir(const Codigo &codigo) {
    conectar();
    const char *sql = "DELETE FROM carteiras WHERE codigo = ?;";
    sqlite3_stmt *stmt;
    bool sucesso = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, codigo.getCodigo().c_str(), -1, SQLITE_STATIC);
        sucesso = sqlite3_step(stmt) == SQLITE_DONE;
    }

    sqlite3_finalize(stmt);
    desconectar();
    return sucesso;
}
