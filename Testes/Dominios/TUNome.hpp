//
// Criado por Gabriel em 22/04/2025.
// Matricula: 241038942

#ifndef TUNOME_HPP
#define TUNOME_HPP
#include "Nome.hpp" //inclui o header da classe Nome que vai ser testada
#include <string> //inclui header string padrao do C++

class TUNome { //declaracao da classe
    private:
        const static std::string NOME_VALIDO; // string usada para teste do NOME_VALIDO
        const static std::string NOME_INVALIDO; //  string usada para teste do NOME_INVALIDO
        Nome* nome; //  ponteiro do objeto nome que sera usado nos testes
        int estadoNome; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA
        
        void setUpNome(); // inicializa o ambiente de teste
        void tearDownNome(); // limpa o ambiente de teste
        void testarCenarioValidoNome(); // testa um nome valido
        void testarCenarioInvalidoNome(); // testa um nome invalido
    public:
        const static int SUCESSO = 0; // inteiro que define sucesso do caso de teste
        const static int FALHA = -1; // inteiro que define falha do caso de teste
        int runNome(); // dereciona a execucaco de todos os testes 
};

#endif
