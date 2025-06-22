//
// Criado por Henrique em 22/04/2025.
// Matricula: 241020840
#include "TUDinheiro.hpp"

 std::string TUDinheiro::DINHEIRO_VALIDO = "20863.67"; // Inicializacao de Dinheiro que passa em todos os testes
 std::string TUDinheiro::DINHEIRO_INVALIDO = "100000000"; // Inicializacao de Dinheiro que falha na validacao


void TUDinheiro::setUpDinheiro() {
	dinheiro = new Dinheiro(); // Aloca um novo objeto Dinheiro para teste
	estadoDinheiro = SUCESSO; // Incializa o estado para SUCESSO
}

void TUDinheiro::tearDownDinheiro() {
	delete dinheiro;// Libera memoria usado do objeto Dinheiro alocado para teste
}

void TUDinheiro::testarCenarioValidoDinheiro() {
	try {
		dinheiro->setDinheiro(DINHEIRO_VALIDO); // Tenta definir um Dinheiro valido
		if(dinheiro->getDinheiro() != std::stod(DINHEIRO_VALIDO)) { // Verifica se o valor foi armazenado corretamente
			estadoDinheiro = FALHA; // Se for diferente do esperado marca como FALHA
		}
	} catch(DominioException &excecao) {// Lanca excecao

		estadoDinheiro = FALHA; // Marca o teste como FALHA
	}
}


void TUDinheiro::testarCenarioInvalidoDinheiro() {
	try {
		dinheiro->setDinheiro(DINHEIRO_INVALIDO); //tenta definir um Dinheiro invalido
		estadoDinheiro = FALHA; // Se conseguir marca como FALHA
	} catch(DominioException &excecao) { // Lanca excecao
		if(dinheiro->getDinheiro() == std::stod(DINHEIRO_INVALIDO)) { // Verifica se o Dinheiro invalido nao foi armazenado
			estadoDinheiro = FALHA; // Se foi armazenado marca como FALHA
		}
	}
}

int TUDinheiro::runDinheiro() {
	setUpDinheiro(); // Prepara para o teste
	testarCenarioValidoDinheiro(); // Executa o teste para cenario valido
	testarCenarioInvalidoDinheiro(); // Executa o teste para cenario invalido
	tearDownDinheiro(); // Libera a memoria do objeto alocado para teste
	return estadoDinheiro; // Retorna o resultado final do teste
}















