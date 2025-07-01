//
// Created by Henrique on 29/06/2025.
//

#ifndef CTRL_CARTEIRA_HPP
#define CTRL_CARTEIRA_HPP

#include "servicoCarteira.hpp"

class CtrlCarteira {
private:
    ServicoCarteira *servico;

public:
    explicit CtrlCarteira(ServicoCarteira *servico);
    void menu(const CPF &cpf);
};

#endif // CTRL_CARTEIRA_HPP
