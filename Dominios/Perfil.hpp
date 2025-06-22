//Autor Cleriston
//Matricula 232001433

/**
 * @file Perfil.hpp
 * @brief Definição da classe Perfil para representar tipos de perfil de investimento.
 */

#ifndef PERFIL_HPP
#define PERFIL_HPP

#include <string>
#include "DominioException.hpp"

/**
 * @class Perfil
 * @brief Armazena e valida perfis de investimento (Conservador, Moderado, Agressivo).
 *
 * @details
 * Validação: Aceita apenas os valores exatos:
 * - "Conservador"
 * - "Moderado"
 * - "Agressivo"
 */

class Perfil {
    private:
        std::string tipoPerfil; ///< Armazena o tipo de perfil válido.

        /**
        * @brief Método privado de validação.
        * @param tipoPerfil String a ser validada.
        * @return true se o perfil for válido, false caso contrário.
        */
        void validarPerfil(const std::string& tipoPerfil);

    public:
        /**
        * @brief Define um perfil após validação.
        * @param tipoPerfil Perfil a ser armazenado.
        * @throw DominioException Se o perfil for inválido.
        */
        void setPerfil(const std::string& tipoPerfil);
        /**
        * @brief Retorna o perfil armazenado.
        * @return std::string Perfil atual (garantidamente válido ou string vazia).
        */
        std::string getPerfil() const {
            return tipoPerfil;
        };
};

#endif // PERFIL_HPP
