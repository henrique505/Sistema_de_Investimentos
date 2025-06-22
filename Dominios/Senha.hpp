//
// Criado por Nyvea em 11/04/2025.
// Matricula: 241040207

#ifndef SENHA_HPP_INCLUDED
#define SENHA_HPP_INCLUDED

#include <string>
#include <stdexcept>
#include "DominioException.hpp"

class Senha{
    private:
        static const int CARACTERES = 6;        //a senha deve possuir 6 caracteres
        std::string senha;                      //a senha é lida como uma string
        void validaSenha(std::string senha);          //retorna true se a senha for valida e false se nao for

    public:
        void setSenha(std::string senha);             //inicializa a senha de acordo input
        std::string getSenha() const;           //retorna a string senha
};

inline std::string Senha::getSenha() const{
    return senha;
}

#endif // SENHA_HPP_INCLUDED
