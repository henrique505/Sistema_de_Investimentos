#ifndef CARTEIRA_HPP_INCLUDED
#define CARTEIRA_HPP_INCLUDED

#include "Dominios.hpp"

/// @class Carteira
/// @brief Entidade que representa uma carteira de investimentos com código, nome e perfil.
class Carteira{
private:
    Codigo codigo;
    Nome nome;
    Perfil perfil;

public:
    /// @brief Define o código da carteira
    /// @param novoCodigo Objeto do domínio Codigo já validado
    void setCodigo(const Codigo& novoCodigo);

    /// @brief Define o nome associado à carteira
    /// @param novoNome Objeto do domínio Nome já validado
    void setNome(const Nome& novoNome);

    /// @brief Define o perfil de investimento
    /// @param novoPerfil Objeto do domínio Perfil já validado
    void setPerfil(const Perfil& novoPerfil);

    /// @brief Retorna o código da carteira
    Codigo getCodigo() const {
        return codigo;
    }

    /// @brief Retorna o nome associado
    Nome getNome() const{
        return nome;
    }

    /// @brief Retorna o perfil de investimento
    Perfil getPerfil() const{
        return perfil;
    }
};

#endif // CARTEIRA_HPP_INCLUDED
