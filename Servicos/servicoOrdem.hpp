//
// Created by Henrique on 29/06/2025.
//

#ifndef SERVICO_ORDEM_HPP
#define SERVICO_ORDEM_HPP

#include "Ordem.hpp"
#include "CPF.hpp"
#include <vector>
#include <sqlite3.h>

class ServicoOrdem {
private:
    sqlite3 *db;

public:
    ServicoOrdem();
    ~ServicoOrdem();

    bool criarTabela();
    bool inserirOrdem(const CPF &cpf, const Ordem &ordem);
    std::vector<Ordem> listarOrdens(const CPF &cpf);
    bool importarDeArquivo(const CPF &cpf, const std::string &caminho);
};

#endif // SERVICO_ORDEM_HPP
