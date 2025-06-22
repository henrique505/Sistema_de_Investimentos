//
// Criado por Nyvea em 18/04/2025.
// Matricula: 241040207

#ifndef TUSENHA_HPP
#define TUSENHA_HPP
#include "Senha.hpp" //inclui o header da classe Senha que vai ser testada
#include <string> //inclui header string padrao do C++

class TUSenha { //declaracao da classe
    private:
        const static std::string SENHA_VALIDA; // string usada para teste da SENHA_VALIDA
        const static std::string SENHA_INVALIDA; //  string usada para teste da SENHA_INVALIDA
        Senha* senha; //  ponteiro do objeto senha que sera usado nos testes
        int estadoSenha; // inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA
        
        void setUpSenha(); // inicializa o ambiente de teste
        void tearDownSenha(); // limpa o ambiente de teste
        void testarCenarioValidoSenha(); // testa uma senha valida
        void testarCenarioInvalidoSenha(); // testa uma senha invalida
    public:
        const static int SUCESSO = 0; // inteiro que define sucesso do caso de teste
        const static int FALHA = -1; // inteiro que define falha do caso de teste
        int runSenha(); // dereciona a execucaco de todos os testes 
};

#endif
