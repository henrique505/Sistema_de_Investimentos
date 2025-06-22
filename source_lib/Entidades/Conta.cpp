#include "Conta.hpp"

void Conta::setCpf(const CPF& novoCpf) {
    this->cpf = novoCpf;
}

void Conta::setNome(const Nome& novoNome) {
    this->nome = novoNome;
}

void Conta::setSenha(const Senha& novaSenha) {
    this->senha = novaSenha;
}
