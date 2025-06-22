//
// Criado por Henrique em 10/04/2025
//  Matricula 241020840

#include "Quantidade.hpp"
#include <string>
#include <algorithm>


// Implementacao do metodo stringParaInteiro
int Quantidade::stringParaInteiro(std::string& quantidade){
    if(quantidade.empty()){ // Verifica se a string eh vazia
        throw DominioException("Por favor, digite algum valor para continuar.");
    }
    if(quantidade.length() > 7){ // verifica se o tamanho da string eh maior que 7, o que indica que o valor ultrapassou o limite
        throw DominioException("Quantidade invalida! O valor que voce digitou esta fora da faixa de valores.");
    }
   
    if(!std::all_of(quantidade.begin(), quantidade.end(), ::isdigit)){ // Verifica se todos os digitos sao numeros
        throw DominioException("O valor da quantidade deve conter apenas numeros.");
    }
      int valor = stoi(quantidade); // Converte o valor de string para um inteiro e armazena na variavel valor
      return valor; 
}
//Implementacao do metodo para validar a quantidade
void Quantidade::validarQuantidade(int& quantidade){
    if(quantidade < 0 || quantidade > 1000000){ // Confere se o valor digitado esta dentro da faixa permitida
        throw DominioException("Quantiade invalida! O valor digitado deve estar entre 0 e 1,000,000");
    } 
    
}
 // Metodo para receber o input do usuario
void Quantidade::setQuantidade(std::string &quantidade){
         int valorInteiro = stringParaInteiro(quantidade); // Chamamento do metodo e atribuicao do valor retornado para uma variavel do tipo int
        
        validarQuantidade(valorInteiro);// Chamamento da funcao que valida a quantidade recebida pelo input
        
        this->quantidade = valorInteiro; // O atributo quantiade finalmente recebe o input depois de todas as validacoes
}
