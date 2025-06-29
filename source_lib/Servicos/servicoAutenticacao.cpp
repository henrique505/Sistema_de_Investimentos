#include "servicoAutenticacao.hpp"
#include <filesystem>
#include <iostream>

ServicoAutenticacao::ServicoAutenticacao() {
    conectar();
    criarTabelaUsuarios();
    desconectar();
}

ServicoAutenticacao::~ServicoAutenticacao() {
    if (db) sqlite3_close(db);
}

void ServicoAutenticacao::conectar() {
    std::filesystem::create_directory("Data");

    int rc = sqlite3_open("Data/usuarios.db", &db);
    if (rc) {
        std::cerr << "Erro ao abrir banco de dados: " << sqlite3_errmsg(db) << std::endl;
        db = nullptr;
    }
}

void ServicoAutenticacao::desconectar() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

void ServicoAutenticacao::criarTabelaUsuarios() {
    const char *sql = "CREATE TABLE IF NOT EXISTS usuarios (cpf TEXT PRIMARY KEY, senha TEXT NOT NULL, nome TEXT NOT NULL);";
    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

bool ServicoAutenticacao::autenticar(const CPF &cpf, const Senha &senha) {
    conectar();

    const char *sql = "SELECT * FROM usuarios WHERE cpf = ? AND senha = ?;";
    sqlite3_stmt *stmt;
    bool sucesso = false;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, senha.getSenha().c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW)
            sucesso = true;
    }

    sqlite3_finalize(stmt);
    desconectar();
    return sucesso;
}

void ServicoAutenticacao::registrar(const CPF &cpf, const Senha &senha, const Nome &nome) {
    conectar();

    const char *sql = "INSERT INTO usuarios (cpf, senha, nome) VALUES (?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, senha.getSenha().c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, nome.getNome().c_str(), -1, SQLITE_STATIC);

        int rc = sqlite3_step(stmt);
        if (rc == SQLITE_DONE) {
            std::cout << "Usuario registrado com sucesso." << std::endl;
        } else {
            std::cerr << "Erro ao inserir usuario: " << sqlite3_errmsg(db) << std::endl;
            std::cerr << "Falha ao registrar conta." << std::endl;
        }
    } else {
        std::cerr << "Erro na preparacao da query: " << sqlite3_errmsg(db) << std::endl;
        std::cerr << "Falha ao registrar conta." << std::endl;
    }

    sqlite3_finalize(stmt);
    desconectar();
}

