#ifndef TUCONTA_HPP
#define TUCONTA_HPP

#include "Conta.hpp"
#include "Dominios.hpp"
#include <string>

class TUConta {
private:
    const std::string CPF_VALIDO = "10145408108";
    const std::string NOME_VALIDO = "Joao Silva";
    const std::string SENHA_VALIDA = "A1b2C#";
    
    Conta* conta;
    int estadoConta;
    
    void setUpConta();
    void tearDownConta();
    void testarCenarioValidoConta();
    
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int runConta();
};

#endif // TUCONTA_HPP
