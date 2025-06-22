#ifndef TUCARTEIRA_HPP_INCLUDED
#define TUCARTEIRA_HPP_INCLUDED

#include "Carteira.hpp"
#include "Dominios.hpp"
#include <string>

class TUCarteira {
private:
    const std::string CODIGO_VALIDO = "12345";
    const std::string NOME_VALIDO = "Joao Silva";
    const std::string PERFIL_VALIDO = "Conservador";

    Carteira* carteira;
    int estadoCarteira;

    void setUpCarteira();
    void tearDownCarteira();
    void testarCenarioValidoCarteira();

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;
    int runCarteira();
};

#endif // TUCARTEIRA_HPP_INCLUDED
