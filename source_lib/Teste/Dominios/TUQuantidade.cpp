//
// Feito por Henrique em 22/04/2025
// Matricula 241020840
#include "TUQuantidade.hpp"

 std::string TUQuantidade::QUANTIDADE_VALIDA = "150000"; // inicializacao de Quantidade que passa em todos os testes
 std::string TUQuantidade::QUANTIDADE_INVALIDA = "111111111";// inicializacao de Quantidade que falha na validacao


void TUQuantidade::setUpQuantidade() { 
    quantidade = new Quantidade(); // aloca um novo objeto Quantidade para teste
    estadoQuantidade = SUCESSO; // incializa o estado para SUCESSO
}

void TUQuantidade::tearDownQuantidade() {
    delete quantidade; // libera memoria usado do objeto Quantidade alocado para teste
}

void TUQuantidade::testarCenarioValidoQuantidade() {
    try { 
        quantidade->setQuantidade(QUANTIDADE_VALIDA); // tenta definir um Quantidade valido
        if( quantidade->getQuantidade() != std::stoi(QUANTIDADE_VALIDA)){ // verifica se o valor foi armazenado corretamente
            estadoQuantidade = FALHA; // se for diferente do esperado marca como FALHA
        }
    } catch(DominioException &excecao) { // lanca excecao
        estadoQuantidade = FALHA; // marca o teste como FALHA
    }
}

void TUQuantidade::testarCenarioInvalidoQuantidade() {
    try {
        quantidade->setQuantidade(QUANTIDADE_INVALIDA); //tenta definir um Quantidade invalido
        estadoQuantidade = FALHA; // se conseguir marca como FALHA
    } catch(DominioException &excecao) { //lanca excecao
        if(quantidade->getQuantidade() == std::stoi(QUANTIDADE_INVALIDA)){ //verifica se o Quantidade invalido nao foi armazenado
            estadoQuantidade = FALHA; // se foi armazenado marca como FALHA
        }
    }
}

int TUQuantidade::runQuantidade() {
    setUpQuantidade(); // prepara para o teste
    testarCenarioValidoQuantidade(); // executa o teste para cenario valido
    testarCenarioInvalidoQuantidade(); // executa o teste para cenario invalido
    tearDownQuantidade(); // libera a memoria do objeto alocado para teste
    return estadoQuantidade; // retorna o resultado final do teste
}
