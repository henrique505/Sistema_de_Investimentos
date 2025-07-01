//
// Created by Henrique on 29/06/2025.
//

#ifndef SERVICOCARTEIRA_HPP
#define SERVICOCARTEIRA_HPP

#include "interfaces.hpp"
#include "DominioException.hpp"
#include <sqlite3.h>

class ServicoCarteira {
private:
    sqlite3 *db;
    void conectar();
    void desconectar();
    void criarTabela();

public:
    ServicoCarteira();
    ~ServicoCarteira();

    bool criarCarteiraPara(const CPF &, const Carteira &);
    std::list<Carteira> listarCarteirasPor(const CPF &);
    Carteira ler(const Codigo &);
    bool editar(const Carteira &);
    bool excluir(const Codigo &);
};

#endif // SERVICOCARTEIRA_HPP


