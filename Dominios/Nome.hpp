//
// Criado por Nyvea em 08/04/2025.
// Matricula: 241040207

#ifndef NOME_HPP_INCLUDED
#define NOME_HPP_INCLUDED

#include <string>
#include "DominioException.hpp"

class Nome{
    private:
        static const int MAXIMO = 21;                                   //limite de caracters do nome: 20 + 1 (do '\0')
        std::string nome;                                               //o nome eh lido como uma string
        void validaNome(std::string nome);                              //verifica se o nome digitado eh valido

    public:
        void setNome(std::string nome);                                 //inicializa o nome se for valido
        std::string getNome() const;                                    //retorna o "nome" do objeto
};

inline std::string Nome::getNome() const{                               //metodo inline para retornar o nome do objeto
    return nome;
}

#endif // NOME_HPP_INCLUDED
