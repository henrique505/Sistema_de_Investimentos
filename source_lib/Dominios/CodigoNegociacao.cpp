//Autor Cleriston
//Matricula 232001433

/**
 * @file CodigoNegociacao.cpp
 * @brief Implementação dos métodos da classe CodigoNegociacao.
 */

#include "CodigoNegociacao.hpp"
#include<ctype.h>

/**
 * @brief Valida se um código de negociação atende aos requisitos.
 *
 * @param codigo String contendo o código a ser validado.
 * @return true Se o código for válido.
 * @throw DominioException Se:
 * - O código estiver vazio ou exceder 12 caracteres (`"Tamanho do codigo invalido!"`).
 * - Contiver caracteres não alfanuméricos ou diferentes de espaço (`"Caractere invalido"`).
 *
 * @note Este método é privado e chamado automaticamente por `setCodigo()`.
 */

void CodigoNegociacao::validarCodigo(const std::string& codigo) {
    if(codigo.empty() || codigo.length() > 12) { // Verifica se a string ta vazia ou tem mais de 12 caracteres
        throw DominioException("Tamanho do codigo invalido!");
    }
    for(char c : codigo) { // percorre a string char por char e verifica se e letra, numero ou espaco
        if(!(isalnum(c) || c == ' ')) { // caso contrario retorna uma excessao
            throw DominioException("Caractere invalido");
        }
    }
}

/**
 * @brief Armazena um código de negociação após validação.
 *
 * @param codigo String contendo o código a ser armazenado.
 * @throw DominioException Herdada de `validarCodigo()` se a validação falhar.
 *
 */

void CodigoNegociacao::setCodigoNegociacao(const std::string& codigo) {
    validarCodigo(codigo);
    this->codigo = codigo;
}
