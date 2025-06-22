//
// Criado por Henrique em 10/04/2025
//  Matricula 241020840

#ifndef QUANTIDADE_HPP
#define QUANTIDADE_HPP
#include <stdexcept> // Biblioteca onde esta contida a  calsse base runtime_error 
#include "DominioException.hpp"
class Quantidade{
        private:
        int quantidade; // Armazena o valor quantidade como um inteiro
        
        void validarQuantidade(int &quantidade); // Metodo para conferir se a quantidade digitada eh valida
        
        int stringParaInteiro(std::string &quantiade); // Metodo para converter o input recebido como string para ser armazenado como inteiro
        
        public: 
        void setQuantidade(std::string &quantidade); // Recebe o input do usuario
        inline int getQuantidade() const{ // Retorna o valor do atributo quantidade 
            return quantidade;
        }
        
        
    
};
#endif
