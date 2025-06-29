#ifndef SERVICOAUTENTICACAO_HPP
#define SERVICOAUTENTICACAO_HPP

#include "interfaces.hpp"
#include "sqlite3.h"
#include <string>
#include <iostream>


class ServicoAutenticacao : public ILNAutenticacao {
private:
    sqlite3 *db = nullptr;
    void conectar();
    void desconectar();
    void criarTabelaUsuarios();

public:
    ServicoAutenticacao();
    ~ServicoAutenticacao();
    bool autenticar(const CPF &, const Senha &) override;
    void registrar(const CPF &, const Senha &, const Nome &) override;
};


#endif // SERVICOAUTENTICACAO_HPP
