//
// Criado por Gabriel em 22/04/2025.
// Matricula: 241038942

#include "TUNome.hpp" // inclusao do header da classe de teste

const std::string TUNome::NOME_VALIDO = "Nyvea Paulla"; // inicializacao de Nome que passa em todos os testes
const std::string TUNome::NOME_INVALIDO = "vinic1us_13";// inicializacao de Nome que falha na validacao


void TUNome::setUpNome() { 
    nome = new Nome(); // aloca um novo objeto data para teste
    estadoNome = SUCESSO; // incializa o estado para SUCESSO
}

void TUNome::tearDownNome() {
    delete nome; // libera memoria usado do objeto nome alocado para teste
}

void TUNome::testarCenarioValidoNome() {
    try { 
        nome->setNome(NOME_VALIDO); // tenta definir um nome valido
        if( nome->getNome() != NOME_VALIDO){ // verifica se o valor foi armazenado corretamente
            estadoNome = FALHA; // se for diferente do esperado marca como FALHA
        }
    } catch(DominioException &excecao) { // lanca excecao
        estadoNome = FALHA; // marca o teste como FALHA
    }
}

void TUNome::testarCenarioInvalidoNome() {
    try {
        nome->setNome(NOME_INVALIDO); //tenta definir um nome invalido
        estadoNome = FALHA; // se conseguir marca como FALHA
    } catch(DominioException &excecao) { //lanca excecao
        if(nome->getNome() == NOME_INVALIDO){ //verifica se o nome invalido nao foi armazenado
            estadoNome = FALHA; // se foi armazenado marca como FALHA
        }
    }
}

int TUNome::runNome() {
    setUpNome(); // prepara para o teste
    testarCenarioValidoNome(); // executa o teste para cenario valido
    testarCenarioInvalidoNome(); // executa o teste para cenario invalido
    tearDownNome(); // libera a memoria do objeto alocado para teste
    return estadoNome; // retorna o resultado final do teste
}
