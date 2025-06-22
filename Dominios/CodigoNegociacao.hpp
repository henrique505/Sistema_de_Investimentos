//Autor Cleriston
//Matricula 232001433

/**
 * @file CodigoNegociacao.hpp
 * @brief Definição da classe CodigoNegociacao para representar códigos de negociação financeira.
 */

#ifndef CODIGONEGOCIACAO_HPP
#define CODIGONEGOCIACAO_HPP

#include<iostream>
#include<string>
#include "DominioException.hpp"

/**
 * @class CodigoNegociacao
 * @brief Representa um código de negociação (ex: "TEST4") com validação.
 *
 * Regras de validação:
 * - Tamanho máximo: 12 caracteres.
 * - Caracteres permitidos: alfanuméricos (A-Z, a-z, 0-9) e espaços.
 */

class CodigoNegociacao {

    private:
        std::string codigo;
        void validarCodigo(const std::string& codigo);

    public:

        /**
        * @brief Define um código após validação.
        * @param codigo String a ser validada (max 12 caracteres alfanuméricos ou espaços).
        * @throw DominioException Se o código for inválido.
        */

        void setCodigoNegociacao(const std::string& codigo);

        /**
        * @brief Retorna o código armazenado (garantidamente válido ou string vazia).
        */

        std::string getCodigoNegociacao() const {
            return codigo;
        }
};

#endif // CODIGONEGOCIACAO_HPP
