//
// Criado por Gabriel em 22/04/2025.
// Matricula: 241038942

#include "TUData.hpp" // inclusao do header da classe de teste

const std::string TUData::DATA_VALIDA = "20250422"; // inicializacao de Data que passa em todos os testes
const std::string TUData::DATA_INVALIDA = "20250229";// inicializacao de Data que falha na validacao


void TUData::setUpData() { 
    data = new Data(); // aloca um novo objeto data para teste
    estadoData = SUCESSO; // incializa o estado para SUCESSO
}

void TUData::tearDownData() {
    delete data; // libera memoria usado do objeto data alocado para teste
}

void TUData::testarCenarioValidoData() {
    try { 
        data->setData(DATA_VALIDA); // tenta definir uma data valida
        if( data->getData() != DATA_VALIDA){ // verifica se o valor foi armazenado corretamente
            estadoData = FALHA; // se for diferente do esperado marca como FALHA
        }
    } catch(DominioException &excecao) { // lanca excecao
        estadoData = FALHA; // marca o teste como FALHA
    }
}

void TUData::testarCenarioInvalidoData() {
    try {
        data->setData(DATA_INVALIDA); //tenta definir uma data invalida
        estadoData = FALHA; // se conseguir marca como FALHA
    } catch(DominioException &excecao) { //lanca excecao
        if(data->getData() == DATA_INVALIDA){ //verifica se a data invalida nao foi armazenado
            estadoData = FALHA; // se foi armazenado marca como FALHA
        }
    }
}

int TUData::runData() {
    setUpData(); // prepara para o teste
    testarCenarioValidoData(); // executa o teste para cenario valido
    testarCenarioInvalidoData(); // executa o teste para cenario invalido
    tearDownData(); // libera a memoria do objeto alocado para teste
    return estadoData; // retorna o resultado final do teste
}
