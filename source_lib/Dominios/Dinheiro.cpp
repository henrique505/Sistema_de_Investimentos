//
// Criado por  Henrique em 05/04/2025.
// Matricula: 241020840

#include "Dinheiro.hpp"

#include <cmath>
#include <stdexcept>
#include <string>
#include <algorithm>

double Dinheiro::stringParaDouble(std::string& valor){
       if(valor.empty()){ // Verifica se a string eh vazia
        throw DominioException("Por favor, digite algum valor para continuar.");
    }
    if(valor.length() > 9){ // verifica se o tamanho da string eh maior que 9, o que indica que o valor ultrapassou o limite
        throw DominioException("Valor invalida! O valor que voce digitou esta fora da faixa de valores.");
    }
   
    if(std::all_of(valor.begin(), valor.end(), ::isalpha)){ // Verifica se todos os digitos sao numeros
        throw DominioException("O valor deve conter apenas numeros.");
    }
      double valorDef = std::stod(valor); // Converte o valor de string para um double e armazena na variavel valorDef
      return valorDef; 
}
// Metodo que arredonda o valor para ter algo significante somente ate a 2a casa decimal
double Dinheiro::arrendodar(const double &valor) {
    return std::round(valor *100.00) / 100.00;
};

void Dinheiro::validarValor(const double &valor) {
    if (valor < 0.00 || valor > 1000000.00) {
        throw DominioException("Valor invalido, voce deve inserir um valor entre 0.01 e 1,000,000.00 ");
    }
    //Se passou por todas as verificacoes, o valor e valida

}

void Dinheiro::setDinheiro(std::string& valor) {
    double valor_T = stringParaDouble(valor);
    valor_T = arrendodar(valor_T);
    validarValor(valor_T);
    this->valor = valor_T;   // Atribui valor arredondado
}
