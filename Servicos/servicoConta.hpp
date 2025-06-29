//
// Created by Henrique on 27/06/2025.
//

#ifndef SERVICOCONTA_HPP
#define SERVICOCONTA_HPP

#include "interfaces.hpp"
#include "DominioException.hpp"
#include "sqlite3.h"

class ServicoConta : public ILNConta {
private:
    sqlite3 *db;
    void conectar();
    void desconectar();
    void criarTabela();

public:
    ServicoConta();
    ~ServicoConta();

    bool criar(const Conta &conta) override;
    Conta ler(const CPF &cpf) override;
    bool editar(const Conta &conta) override;
    bool excluir(const CPF &cpf) override;
};

#endif // SERVICOCONTA_HPP

