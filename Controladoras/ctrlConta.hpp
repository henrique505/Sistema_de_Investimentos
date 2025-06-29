//
// Created by Henrique on 28/06/2025.
//

#ifndef CTRLCONTA_HPP
#define CTRLCONTA_HPP
#include "interfaces.hpp"
#include "servicoConta.hpp"
#include <iostream>

class CtrlConta : public IUConta {
private:
    ILNConta *servico;
public:
    void setCntr(ILNConta *cntr);
    void menu(const CPF &cpf);
    void criar() override;
    void editar() override;
    void excluir() override;
    void ler() override;
};
#endif //CTRLCONTA_HPP
