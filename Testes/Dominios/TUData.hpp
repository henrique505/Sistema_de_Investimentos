//
// Criado por Gabriel em 22/04/2025.
// Matricula: 241038942

#ifndef TUDATA_HPP
#define TUDATA_HPP
#include "Data.hpp" //inclui o header da classe Data que vai ser testada
#include <string> //inclui header string padrao do C++

class TUData { //declaracao da classe
    private:
        const static std::string DATA_VALIDA; // string usada para teste da DATA_VALIDA
        const static std::string DATA_INVALIDA; //  string usada para teste da DATA_INVALIDA
        Data* data; //  ponteiro do objeto data que sera usado nos testes
        int estadoData; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA
        
        void setUpData(); // inicializa o ambiente de teste
        void tearDownData(); // limpa o ambiente de teste
        void testarCenarioValidoData(); // testa uma data valida
        void testarCenarioInvalidoData(); // testa uma data invalida
    public:
        const static int SUCESSO = 0; // inteiro que define sucesso do caso de teste
        const static int FALHA = -1; // inteiro que define falha do caso de teste
        int runData(); // dereciona a execucaco de todos os testes 
};

#endif
