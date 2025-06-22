//
// Criado por Gabriel em 15/04/2025.
// Matricula: 241038942

#ifndef TUCPF_HPP
#define TUCPF_HPP
#include "Cpf.hpp" //inclui o header da classe CPF que vai ser testada
#include <string> //inclui header string padrao do C++

class TUCpf { //declaracao da classe
    private:
        const static std::string CPF_VALIDO; // string usada para teste do CPF_VALIDO
        const static std::string CPF_INVALIDO; //  string usada para teste do CPF_INVALIDO
        CPF* cpf; //  ponteiro do objeto cpf que sera usado nos testes
        int estadoCpf; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA
        
        void setUpCpf(); // inicializa o ambiente de teste
        void tearDownCpf(); // limpa o ambiente de teste
        void testarCenarioValidoCpf(); // testa um cpf valido
        void testarCenarioInvalidoCpf(); // testa um cpf invalido
    public:
        const static int SUCESSO = 0; // inteiro que define sucesso do caso de teste
        const static int FALHA = -1; // inteiro que define falha do caso de teste
        int runCpf(); // dereciona a execucaco de todos os testes 
};

#endif
