//
// Criado por Gabriel em 18/04/2025.
// Matricula: 241038942

#ifndef TUCODIGO_HPP
#define TUCODIGO_HPP
#include "Codigo.hpp" //inclui o header da classe Codigo que vai ser testada
#include <string> //inclui header string padrao do C++

class TUCodigo {
  private:
        const static std::string CODIGO_VALIDO; // string usada para teste do CODIGO_VALIDO
        const static std::string CODIGO_INVALIDO; //  string usada para teste do CODIGO_INVALIDO
        Codigo* codigo; //  ponteiro do objeto codigo que sera usado nos testes
        int estadoCodigo; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA
        
        void setUpCodigo(); // inicializa o ambiente de teste
        void tearDownCodigo(); // limpa o ambiente de teste
        void testarCenarioValidoCodigo(); // testa um codigo valido
        void testarCenarioInvalidoCodigo(); // testa um codigo invalido
    public:
        const static int SUCESSO = 0; // inteiro que define sucesso do caso de teste
        const static int FALHA = -1; // inteiro que define falha do caso de teste
        int runCodigo(); // dereciona a execucaco de todos os testes 
};

#endif
