//
// Criado por Henrique em 22/04/2025.
// Matricula: 241020840
#ifndef TUDINHEIRO_HPP
#define TUDINHEIRO_HPP
#include "Dinheiro.hpp"
#include <string>

class TUDinheiro {
private:
	static std::string DINHEIRO_VALIDO; // String usada para teste do DINHEIRO_VALIDO
	static std::string DINHEIRO_INVALIDO; // String usada para teste do DINHEIRO_INVALIDO
	Dinheiro* dinheiro; //  paraonteiro do objeto Dinheiro que sera usado nos testes
	int estadoDinheiro; // Inteiro que ira armazenar o estado de teste, seja SUCESSO ou FALHA

	void setUpDinheiro(); // Inicializa o ambiente de teste
	void tearDownDinheiro(); // Limpa o ambiente de teste
	void testarCenarioValidoDinheiro(); // Testa um valor de dinheiro valido
	void testarCenarioInvalidoDinheiro(); // Testa um valor de dinheiro invalido

public:
	const static int SUCESSO = 0; // Inteiro que define sucesso do caso de teste
	const static int FALHA = -1; // Inteiro que define falha do caso de teste
	int runDinheiro(); // Direciona a execucaco de todos os testes

};

#endif //TUDINHEIRO_HPP
