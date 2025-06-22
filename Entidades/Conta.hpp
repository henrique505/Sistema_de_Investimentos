#ifndef CONTA_HPP
#define CONTA_HPP

#include "Dominios.hpp"


class Conta{
    private:
        CPF cpf;
        Nome nome;
        Senha senha;

    public:
        void setCpf(const CPF& novoCpf);
        void setNome(const Nome& novoNome);
        void setSenha(const Senha& novaSenha);

        CPF getCpf() const {
            return cpf;
        }
        Nome getNome() const{
            return nome;
        }
        Senha getSenha() const{
            return senha;
        }

};

#endif //CONTA_HPP
