//Autor Cleriston
//Matricula 232001433

/**
 * @file Perfil.cpp
 * @brief Implementação dos métodos da classe Perfil.
 */

#include "Perfil.hpp"

/**
 * @brief Valida se o perfil está entre as opções permitidas.
 *
 * @param tipoPerfil String a ser validada.
 *
 * @throw DominioException Com mensagem "Tipo de perfil incorreto!" se a validação falhar.
 *
 * @note Comparação direta sem transformação de caso (case-sensitive).
 */

void Perfil::validarPerfil(const std::string& tipoPerfil) {
    if(tipoPerfil != "Conservador" &&
       tipoPerfil != "Moderado"    &&
       tipoPerfil != "Agressivo")
    {
        throw DominioException("Tipo de perfil incorreto!");
    } // Aceita somente com a primeira letra maiuscula
}

/**
 * @brief Armazena o perfil se for válido.
 *
 * @param tipoPerfil Perfil a ser definido.
 *
 */

void Perfil::setPerfil(const std::string& tipoPerfil) {
    validarPerfil(tipoPerfil);
    this->tipoPerfil = tipoPerfil;
}
