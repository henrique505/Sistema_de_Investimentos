//
// Criado por Nyvea em 08/04/2025.
// Matricula: 241040207

#include "Nome.hpp"
#include <string>
#include <cctype>

void Nome::validaNome(std::string nome){
    unsigned int i;

    if(nome.length() > MAXIMO){                          //confere se o nome ultrapassa o limite de caracteres
        throw DominioException("Nome invalido! Nome deve conter no maximo 20 caracteres");      //se sim, o nome eh invalido
    }
    else if((nome.length() < 1) || (nome.length() == 1 && nome[0] == ' ')){                                                     //confere se o nome tem ao menos um caracter, ou se esse caracter eh um espaco
        throw DominioException("Nome invalido! Nome deve conter no minimo 1 caracter que deve ser diferente de ' '.");
    }

    for(i = 0; i < nome.length() - 1; i++){                                     //perpassa caracter por caracter
        if((nome[i] == ' ')&&(nome[i+1] == ' ')){                               //se houver dois espaços consecutivos, o nome eh invalido
            throw DominioException("Nome invalido! Nome nao pode conter dois espacos consecultivos");
        }

        if(!isdigit(nome[i]) && !isupper(nome[i]) && !islower(nome[i]) && nome[i] != ' '){        //se o caracter nao for um numero e/ou nao for uma letra, o nome eh invalido
            throw DominioException("Nome invalido! O nome deve conter apenas letras ou numeros.");
        }
    }

    if(!isdigit(nome[i]) && !isupper(nome[i]) && !islower(nome[i]) && nome[i] != ' '){           //confere o ultimo digito, ja que na iteracao o ultimo digito nao eh conferido
            throw DominioException("Nome invalido! O nome deve conter apenas letras ou numeros.");
    }
}

void Nome::setNome(std::string nome){
    Nome::validaNome(nome);

    this->nome = nome;
}
