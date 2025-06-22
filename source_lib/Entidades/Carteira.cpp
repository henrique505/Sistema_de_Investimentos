#include "Carteira.hpp"

void Carteira::setCodigo(const Codigo& novoCodigo) {
    this->codigo = novoCodigo;
}

void Carteira::setNome(const Nome& novoNome) {
    this->nome = novoNome;
}

void Carteira::setPerfil(const Perfil& novoPerfil) {
    this->perfil = novoPerfil;
}