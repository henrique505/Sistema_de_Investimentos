//
// Created by Henrique on 28/06/2025.
//

#ifndef CTRL_CONTA_HPP
#define CTRL_CONTA_HPP

#include <iostream>
#include "interfaces.hpp"
#include "servicoConta.hpp"
#include "ctrlCarteira.hpp"
#include "servicoCarteira.hpp"

class CtrlConta : public IUConta {
private:
    ILNConta *servico = nullptr;
    CtrlCarteira *ctrlCarteira = nullptr;
    ServicoCarteira *servicoCarteira = nullptr;

public:
    void setCntr(ILNConta *cntr);
    void setCtrlCarteira(CtrlCarteira *cntrCarteira);
    void setServicoCarteira(ServicoCarteira *servicoCarteira);

    void menu(const CPF &cpf);

    void criar() override;
    void editar() override {} // não usado diretamente
    void excluir() override {} // não usado diretamente
    void ler() override;

    void editar(const CPF &cpf);
    void excluir(const CPF &cpf);
};

#endif // CTRL_CONTA_HPP

