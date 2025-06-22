//
// Criado por Gabriel em 15/04/2025.
// Matricula: 241038942

#include "TUCpf.hpp" // inclusao do header da classe de teste

const std::string TUCpf::CPF_VALIDO = "10145408108"; // inicializacao de CPF que passa em todos os testes
const std::string TUCpf::CPF_INVALIDO = "11111111111";// inicializacao de CPF que falha na validacao


void TUCpf::setUpCpf() { 
    cpf = new CPF(); // aloca um novo objeto cpf para teste
    estadoCpf = SUCESSO; // incializa o estado para SUCESSO
}

void TUCpf::tearDownCpf() {
    delete cpf; // libera memoria usado do objeto cpf alocado para teste
}

void TUCpf::testarCenarioValidoCpf() {
    try { 
        cpf->setCPF(CPF_VALIDO); // tenta definir um cpf valido
        if( cpf->getCPF() != CPF_VALIDO){ // verifica se o valor foi armazenado corretamente
            estadoCpf = FALHA; // se for diferente do esperado marca como FALHA
        }
    } catch(DominioException &excecao) { // lanca excecao
        estadoCpf = FALHA; // marca o teste como FALHA
    }
}

void TUCpf::testarCenarioInvalidoCpf() {
    try {
        cpf->setCPF(CPF_INVALIDO); //tenta definir um cpf invalido
        estadoCpf = FALHA; // se conseguir marca como FALHA
    } catch(DominioException &excecao) { //lanca excecao
        if(cpf->getCPF() == CPF_INVALIDO){ //verifica se o cpf invalido nao foi armazenado
            estadoCpf = FALHA; // se foi armazenado marca como FALHA
        }
    }
}

int TUCpf::runCpf() {
    setUpCpf(); // prepara para o teste
    testarCenarioValidoCpf(); // executa o teste para cenario valido
    testarCenarioInvalidoCpf(); // executa o teste para cenario invalido
    tearDownCpf(); // libera a memoria do objeto alocado para teste
    return estadoCpf; // retorna o resultado final do teste
}
