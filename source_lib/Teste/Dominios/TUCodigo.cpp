//
// Criado por Gabriel em 18/04/2025.
// Matricula: 241038942

#include "TUCodigo.hpp" // inclusao do header da classe de teste

const std::string TUCodigo::CODIGO_VALIDO = "12345"; // inicializacao de Codigo que passa em todos os testes
const std::string TUCodigo::CODIGO_INVALIDO = "1111";// inicializacao de Codigo que falha na validacao


void TUCodigo::setUpCodigo() { 
    codigo = new Codigo(); // aloca um novo objeto codigo para teste
    estadoCodigo = SUCESSO; // incializa o estado para SUCESSO
}

void TUCodigo::tearDownCodigo() {
    delete codigo; // libera memoria usado do objeto codigo alocado para teste
}   

void TUCodigo::testarCenarioValidoCodigo() {
    try { 
        codigo->setCodigo(CODIGO_VALIDO); // tenta definir um codigo valido
        if( codigo->getCodigo() != CODIGO_VALIDO){ // verifica se o valor foi armazenado corretamente
            estadoCodigo = FALHA; // se for diferente do esperado marca como FALHA
        }
    } catch(DominioException &excecao) { // lanca excecao
        estadoCodigo = FALHA; // marca o teste como FALHA
    }
}

void TUCodigo::testarCenarioInvalidoCodigo() {
    try {
        codigo->setCodigo(CODIGO_INVALIDO); //tenta definir um codigo invalido
        estadoCodigo = FALHA; // se conseguir marca como FALHA
    } catch(DominioException &excecao) { //lanca excecao
        if(codigo->getCodigo() == CODIGO_INVALIDO){ //verifica se o codigo invalido nao foi armazenado
            estadoCodigo = FALHA; // se foi armazenado marca como FALHA
        }
    }
}

int TUCodigo::runCodigo() {
    setUpCodigo(); // prepara para o teste
    testarCenarioValidoCodigo(); // executa o teste para cenario valido
    testarCenarioInvalidoCodigo(); // executa o teste para cenario invalido
    tearDownCodigo(); // libera a memoria do objeto alocado para teste
    return estadoCodigo; // retorna o resultado final do teste
}
