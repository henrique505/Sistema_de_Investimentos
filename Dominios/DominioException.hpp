/**
 * @file DominioException.hpp
 * @brief Definição da classe de exceção para domínios inválidos.
 */

#ifndef DOMINIO_EXCEPTION_HPP
#define DOMINIO_EXCEPTION_HPP

#include <stdexcept>
#include <string>

/**
 * @class DominioException
 * @brief Exceção lançada quando uma validação de domínio falha.
 *
 * @details
 * Herda de std::runtime_error para fornecer mensagens de erro descritivas.
 * Usada pelas classes de domínio para
 * indicar violações das regras de validação.
 */

class DominioException : public std::runtime_error {
    
    /**
     * @brief Constrói uma exceção com mensagem de erro.
     * @param mensagem Descrição do erro (ex: "Tamanho inválido").
     * 
     * @note A mensagem é repassada à classe base std::runtime_error.
     * @warning Não use mensagens genéricas como "Erro". Seja específico.
     * 
     * @example
     * throw DominioException("Código contém caracteres inválidos");
     */
    public:
        explicit DominioException(const std::string& mensagem)
         : std::runtime_error(mensagem) {} // passa a mensagem para o construtor da classe base
 };

#endif // DOMINIO_EXCEPTION_HPP
