//
// Created by Henrique on 22/06/2025.
//

#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include "Entidades.hpp"

// Interface da camada de apresentação (IU)
class IUConta {
public:
    virtual void criar() = 0;
    virtual void editar() = 0;
    virtual void excluir() = 0;
    virtual void ler() = 0;
    virtual ~IUConta() {}
};

class IUCarteira {
public:
    virtual void criar() = 0;
    virtual void editar() = 0;
    virtual void excluir() = 0;
    virtual void ler() = 0;
    virtual void listar() = 0;
    virtual ~IUCarteira() {}
};

class IUOrdem {
public:
    virtual void criar() = 0;
    virtual void excluir() = 0;
    virtual void ler() = 0;
    virtual void listarPorCarteira() = 0;
    virtual ~IUOrdem() {}
};

class IUAutenticacao {
public:
    virtual bool autenticar() = 0;
    virtual void setCntr(ILNAutenticacao *cntr) = 0;
    virtual ~IUAutenticacao() {}
};

// Interface da camada de lógica de negócio (LN)
class ILNConta {
public:
    virtual bool criar(const Conta &conta) = 0;
    virtual Conta ler(const CPF &cpf) = 0;
    virtual bool editar(const Conta &conta) = 0;
    virtual bool excluir(const CPF &cpf) = 0;
    virtual ~ILNConta() {}
};

class ILNCarteira {
public:
    virtual bool criar(const Carteira &carteira) = 0;
    virtual Carteira ler(const Codigo &codigo) = 0;
    virtual bool editar(const Carteira &carteira) = 0;
    virtual bool excluir(const Codigo &codigo) = 0;
    virtual list<Carteira> listarPorConta(const CPF &cpf) = 0;
    virtual ~ILNCarteira() {}
};

class ILNOrdem {
public:
    virtual bool criar(const Ordem &ordem) = 0;
    virtual Ordem ler(const Codigo &codigo) = 0;
    virtual bool excluir(const Codigo &codigo) = 0;
    virtual list<Ordem> listarPorCarteira(const Codigo &codigoCarteira) = 0;
    virtual ~ILNOrdem() {}
};

class ILNAutenticacao {
public:
    virtual bool autenticar(const CPF &cpf, const Senha &senha) = 0;
    virtual ~ILNAutenticacao() {}
};

#endif //INTERFACES_HPP
