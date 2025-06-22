/**
 * @file TUCodigoNegociacao.hpp
 * @brief Definição dos testes unitários para CodigoNegociacao.
 */

#ifndef TUCODIGONEGOCIACAO_HPP
#define TUCODIGONEGOCIACAO_HPP

#include "CodigoNegociacao.hpp"
#include <string>

/**
 * @class TUCodigoNegociacao
 * @brief Testa os cenários válidos e inválidos para CodigoNegociacao.
 */

class TUCodigoNegociacao {
  private:
        const static std::string CODIGO_NEGOCIACAO_VALIDO;   ///< Código válido padrão ("TEST4")
        const static std::string CODIGO_NEGOCIACAO_INVALIDO; ///< Código inválido padrão ("TEST#4")
        CodigoNegociacao* codigoNegociacao;      ///< Instância sob teste
        int estadoCodigoNegociacao;              ///< Estado do teste (SUCESSO/FALHA)

        /**
        * @brief Configura o ambiente de teste.
        */
        void setUpCodigoNegociacao();

        /**
        * @brief Libera recursos após o teste.
        */
        void tearDownCodigoNegociacao();

        /**
        * @brief Testa cenário com código válido.
        */
        void testarCenarioValidoCodigoNegociacao();

        /**
        * @brief Testa cenário com código inválido.
        */
        void testarCenarioInvalidoCodigoNegociacao();

    public:
        const static int SUCESSO = 0; ///< Código de sucesso
        const static int FALHA = -1;  ///< Código de falha

        /**
        * @brief Executa o conjunto de testes.
        * @return int SUCESSO se todos os testes passarem, FALHA caso contrário.
        */
        int runCodigoNegociacao();
};
#endif // TUCODIGONEGOCIACAO_HPP
