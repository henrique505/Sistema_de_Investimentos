//
// Feito por Henrique em 22/04/2025
// Matricula: 241020840
#ifndef TUQUANTIDADE_HPP
#define TUQUANTIDADE_HPP
#include "Quantidade.hpp"
#include <string>

class TUQuantidade{
        private:
         static std::string QUANTIDADE_VALIDA; // String usada para teste da QUANTIDADE_VALIDA
         static std::string QUANTIDADE_INVALIDA; // String usada para teste da QUANTIDADE_INVALIDA
        Quantidade* quantidade; //  Ponteiro do objeto Quantidade que sera usado nos testes
        int estadoQuantidade; // Inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA
        
        void setUpQuantidade(); // Inicializa o ambiente de teste
        void tearDownQuantidade(); // Limpa o ambiente de teste
        void testarCenarioValidoQuantidade(); // Testa um Quantidade valido
        void testarCenarioInvalidoQuantidade(); // Testa um Quantidade invalido
    public:
        const static int SUCESSO = 0; // Inteiro que define sucesso do caso de teste
        const static int FALHA = -1; // Inteiro que define falha do caso de teste
        int runQuantidade(); // Direciona a execucaco de todos os testes 

    
};
#endif 
