#ifndef CTRLAUTENTICACAO_HPP
#define CTRLAUTENTICACAO_HPP

#include "interfaces.hpp"
#include "servicoAutenticacao.hpp"
#include <iostream>

class CtrlAutenticacao : public IUAutenticacao {
private:
    ILNAutenticacao *servico;
    ILNConta *servicoConta;
    IUConta *ctrlConta = nullptr;  // interface da camada de apresentação da conta


public:
    void setCtrlConta(IUConta *cntrConta);
    void setCntr(ILNAutenticacao *cntr) override;
    bool autenticar() override;
    void menu();  // exibe menu: login, registrar, sair
    void setCtrlConta(ILNConta *cntrConta);
};

#endif // CTRLAUTENTICACAO_HPP
