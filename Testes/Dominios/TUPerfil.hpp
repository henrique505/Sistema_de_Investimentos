//Autor Cleriston
//Matricula 232001433

/**
 * @file TUPerfil.hpp
 * @brief Definição da classe de testes para Perfil.
 */

#ifndef TUPERFIL_HPP
#define TUPERFIL_HPP

#include "Perfil.hpp"
#include <string>

/**
 * @class TUPerfil
 * @brief Testes unitários para a classe Perfil.
 */

class TUPerfil {
  private:
        const static std::string PERFIL_VALIDO;   ///< Valor válido padrão ("Conservador").
        const static std::string PERFIL_INVALIDO; ///< Valor inválido padrão ("Agresssivo").
        Perfil* perfil;                          ///< Instância sob teste.
        int estadoPerfil;                        ///< Estado do teste (SUCESSO/FALHA).

        /**
        * @brief Configura o ambiente de teste.
        */
        void setUpPerfil();
        /**
        * @brief Libera recursos após o teste.
        */
        void tearDownPerfil();
        /**
        * @brief Testa cenário com perfil válido.
        */
        void testarCenarioValidoPerfil();
        /**
        * @brief Testa cenário com perfil inválido.
        */
        void testarCenarioInvalidoPerfil();

    public:
        const static int SUCESSO = 0; ///< Código de sucesso.
        const static int FALHA = -1;  ///< Código de falha.

        /**
        * @brief Executa o conjunto de testes.
        * @return int SUCESSO se todos os testes passarem, FALHA caso contrário.
        */
        int runPerfil();
};
#endif // TUPERFIL_HPP
