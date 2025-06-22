//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

#include "Codigo.hpp"
#include <string>
#include <algorithm>

void Codigo::validarCodigo(const std::string& codigoInserido) {

	if(codigoInserido.empty()){ //verificacao se foi digitado algo
	    throw DominioException("Por favor, digite algum valor para continuar");
	}

	if(codigoInserido.length() != 5){ // verificacao se foi inserido exatamente 5 caracteres
	    throw DominioException("O tamanho esta invalido! Codigo deve conter exatamente 5 digitos.");
	}

	bool todos_numeros = std::all_of(codigoInserido.begin(), codigoInserido.end(), [](char c) { // verificacao se sao todos caracteres numericos
		return std::isdigit(static_cast<unsigned char>(c));
	});

    if(!todos_numeros){ // tratamento em caso de input invalido
        throw DominioException("O Codigo deve conter apenas digitos!");
    }


}

void Codigo::setCodigo(const std::string& numeroCodigo) {
	validarCodigo(numeroCodigo);

	this->numeroCodigo = numeroCodigo;
}
