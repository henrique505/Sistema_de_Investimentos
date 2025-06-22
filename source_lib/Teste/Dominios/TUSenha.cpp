//
// Criado por Nyvea em 18/04/2025.
// Matricula: 241040207

#include "TUSenha.hpp" // inclusao do header da classe de teste

const std::string TUSenha::SENHA_VALIDA = "56gH&n"; // inicializacao de Senha que passa em todos os testes
const std::string TUSenha::SENHA_INVALIDA = "m%12s5";// inicializacao de Senha que falha na validacao


void TUSenha::setUpSenha() { 
    senha = new Senha(); // aloca um novo objeto senha para teste
    estadoSenha = SUCESSO; // incializa o estado para SUCESSO
}

void TUSenha::tearDownSenha() {
    delete senha; // libera memoria usado do objeto senha alocado para teste
}

void TUSenha::testarCenarioValidoSenha() {
    try { 
        senha->setSenha(SENHA_VALIDA); // tenta definir uma senha valida
        if( senha->getSenha() != SENHA_VALIDA){ // verifica se o valor foi armazenado corretamente
            estadoSenha = FALHA; // se for diferente do esperado marca como FALHA
        }
    } catch(DominioException &excecao) { // lanca excecao
        estadoSenha = FALHA; // marca o teste como FALHA
    }
}

void TUSenha::testarCenarioInvalidoSenha() {
    try {
        senha->setSenha(SENHA_INVALIDA); //tenta definir uma senha invalida
        estadoSenha = FALHA; // se conseguir marca como FALHA
    } catch(DominioException &excecao) { //lanca excecao
        if(senha->getSenha() == SENHA_INVALIDA){ //verifica se a senha invalida nao foi armazenado
            estadoSenha = FALHA; // se foi armazenado marca como FALHA
        }
    }
}

int TUSenha::runSenha() {
    setUpSenha(); // prepara para o teste
    testarCenarioValidoSenha(); // executa o teste para cenario valido
    testarCenarioInvalidoSenha(); // executa o teste para cenario invalido
    tearDownSenha(); // libera a memoria do objeto alocado para teste
    return estadoSenha; // retorna o resultado final do teste
}
