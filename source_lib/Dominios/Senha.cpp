//
// Criado por Nyvea em 11/04/2025.
// Matricula: 241040207

#include "Senha.hpp"
#include <string>
#include <cctype>

void Senha::validaSenha(std::string senha){
    int i, j;
    bool numero, maiuscula, minuscula, caractereEspecial;                               //variaveis para conferir se a senha inserida possui todos os caracteres necessarios
    numero = maiuscula = minuscula = caractereEspecial = false;                         //inicializacao das variaveis como falsas

    if((senha.length() > CARACTERES)||(senha.length() < CARACTERES)){                   //confere se a senha possui 6 caracteres
        throw DominioException("Tamanho invalido! Senha deve conter exatamente 6 caracteres");
    }

    for(i = 0; i < CARACTERES; i++){                                                    //iteracoes para conferir caracter por caracter
        if(isupper(senha[i])){                                                          //se ha letra maiucula, a variavel eh verdadeira
            maiuscula = true;
        }

        if(islower(senha[i])){                                                          //se ha letra minuscula, a variavel eh verdadeira
            minuscula = true;
        }

        if(isdigit(senha[i])){                                                          //se ha numero, a variavel eh verdadeira
            numero = true;
        }

        if((senha[i] == '#')||(senha[i] == '$')||(senha[i] == '%')||(senha[i] == '&')){ //se ha um dos caracteres especiais previstos, a variavel eh verdadeira
            caractereEspecial = true;
        }

        for(j = 0; j < i; j++){                                                         //iteracoes para comparar com os outros caracteres
            if(senha[i] == senha[j]){                                                   //se ha dois caracteres iguais, a senha eh invalida
                throw DominioException("Formato invalido! Senha não pode conter dois caracteres iguais");
            }
        }
    }

    if(!maiuscula){
        throw DominioException("Formato invalido! Senha nao possui letra maiuscula");
    } else if(!minuscula){
        throw DominioException("Formato invalido! Senha nao possui letra minuscula");
    } else if(!numero){
        throw DominioException("Formato invalido! Senha nao possui numero");
    } else if(!caractereEspecial){
        throw DominioException("Formato invalido! Senha nao possui caracter especial");
    }                                                                    //a senha cumpre todos os requisitos e eh valida
}

void Senha::setSenha(std::string senha){
    Senha::validaSenha(senha);                                                            //verifica a senha

    this->senha = senha;                                                                //se a senha for valida, atribui a string a variavel do objeto senha
}
