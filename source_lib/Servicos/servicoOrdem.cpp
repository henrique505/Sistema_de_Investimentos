// servicoOrdem.cpp
#include "servicoOrdem.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

ServicoOrdem::ServicoOrdem() {
    sqlite3_open("Data/ordens.db", &db);

    const char *sql = "CREATE TABLE IF NOT EXISTS ordens ("
                      "cpf TEXT NOT NULL,"
                      "codigo TEXT NOT NULL,"
                      "codigo_negociacao TEXT NOT NULL,"
                      "data TEXT NOT NULL,"
                      "preco TEXT NOT NULL,"
                      "quantidade TEXT NOT NULL);";

    char *errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Erro ao criar tabela: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }
}

ServicoOrdem::~ServicoOrdem() {
    if (db) {
        sqlite3_close(db);
    }
}

bool ServicoOrdem::inserirOrdem(const CPF &cpf, const Ordem &ordem) {
    const char *sql = "INSERT INTO ordens (cpf, codigo, codigo_negociacao, data, preco, quantidade) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, ordem.getCodigo().getCodigo().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, ordem.getCodigoNegociacao().getCodigoNegociacao().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, ordem.getData().getData().c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, std::to_string(ordem.getDinheiro().getDinheiro()).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 6, std::to_string(ordem.getQuantidade().getQuantidade()).c_str(), -1, SQLITE_TRANSIENT);

    bool sucesso = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return sucesso;
}

std::vector<Ordem> ServicoOrdem::listarOrdens(const CPF &cpf) {
    std::vector<Ordem> ordens;
    const char *sql = "SELECT codigo, codigo_negociacao, data, preco, quantidade FROM ordens WHERE cpf = ?;";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK) {
        return ordens;
    }

    sqlite3_bind_text(stmt, 1, cpf.getCPF().c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Ordem ordem;

        Codigo cod; cod.setCodigo(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 0)));
        CodigoNegociacao codNeg; codNeg.setCodigoNegociacao(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1)));
        Data data; data.setData(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 2)));

        Dinheiro preco;
        std::string precoStr(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 3)));
        preco.setDinheiro(precoStr);

        Quantidade qtd;
        std::string qtdStr(reinterpret_cast<const char *>(sqlite3_column_text(stmt, 4)));
        qtd.setQuantidade(qtdStr);

        ordem.setCodigo(cod);
        ordem.setCodigoNegociacao(codNeg);
        ordem.setData(data);
        ordem.setDinheiro(preco);
        ordem.setQuantidade(qtd);

        ordens.push_back(ordem);
    }

    sqlite3_finalize(stmt);
    return ordens;
}
bool ServicoOrdem::importarDeArquivo(const CPF &cpf, const std::string &caminho) {
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir arquivo: " << caminho << "\n";
        return false;
    }

    std::string linha;
    while (getline(arquivo, linha)) {
        if (linha.length() < 126) continue;

        try {
            std::string codNegStr = linha.substr(12, 12);
            std::string dataStr = linha.substr(2, 8);
            std::string precoStr = linha.substr(113, 13);
            std::string qtdStr = "1"; // valor fixo

            double precoDouble = std::stod(precoStr) / 100.0;
            std::string precoStrConvertido = std::to_string(precoDouble);

            CodigoNegociacao codNeg; codNeg.setCodigoNegociacao(codNegStr);
            Data data; data.setData(dataStr);
            Dinheiro preco; preco.setDinheiro(precoStrConvertido);
            Quantidade qtd; qtd.setQuantidade(qtdStr);

            Ordem ordem;
            ordem.setCodigoNegociacao(codNeg);
            ordem.setData(data);
            ordem.setDinheiro(preco);
            ordem.setQuantidade(qtd);

            inserirOrdem(cpf, ordem);
        } catch (const std::exception &e) {
            std::cerr << "Erro ao importar linha: " << e.what() << "\n";
        }
    }

    arquivo.close();
    return true;
}

