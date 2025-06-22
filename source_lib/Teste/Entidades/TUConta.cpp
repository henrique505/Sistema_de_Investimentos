#include "TUConta.hpp"

    
void TUConta::setUpConta() {
    conta = new Conta();
    estadoConta = SUCESSO;
}

void TUConta::tearDownConta() {
    delete conta;
}

void TUConta::testarCenarioValidoConta() {
    CPF cpf;
    Nome nome;
    Senha senha;
    
    cpf.setCPF(CPF_VALIDO);
    nome.setNome(NOME_VALIDO);
    senha.setSenha(SENHA_VALIDA);
        
    conta->setCpf(cpf);
    conta->setNome(nome);
    conta->setSenha(senha);
        
    // Verifica se os valores foram armazenados corretamente
    if (conta->getCpf().getCPF() != CPF_VALIDO ||
        conta->getNome().getNome() != NOME_VALIDO ||
        conta->getSenha().getSenha() != SENHA_VALIDA) {
        estadoConta = FALHA;
    }
    
}

int TUConta::runConta() {
    setUpConta();
    testarCenarioValidoConta();
    tearDownConta();
    return estadoConta;
}
