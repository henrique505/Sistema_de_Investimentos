//Autor Cleriston
//Matricula 232001433

/**
 * @file TUPerfil.cpp
 * @brief Implementação dos testes para a classe Perfil.
 */

#include "TUPerfil.hpp"

// Valores pre-definidos para os testes
const std::string TUPerfil::PERFIL_VALIDO = "Conservador";
const std::string TUPerfil::PERFIL_INVALIDO = "Agresssivo";

/**
 * @brief Prepara o ambiente antes de cada teste.
 * - Aloca uma nova instância de Perfil.
 * - Define o estado inicial como SUCESSO.
*/

void TUPerfil::setUpPerfil() {
    perfil = new Perfil();
    estadoPerfil = SUCESSO;
}

/**
 * @brief Libera recursos após cada teste.
 * - Deleta a instância de Perfil.
*/

void TUPerfil::tearDownPerfil() {
    delete perfil; // Libera memoria alocada
}

/**
 * @brief Testa a aceitação de um valor válido.
 * - Verifica se setPerfil() não lança exceção.
 * - Verifica se o valor foi armazenado corretamente.
*/

void TUPerfil::testarCenarioValidoPerfil() {
    try {
        perfil->setPerfil(PERFIL_VALIDO);
        if (perfil->getPerfil() != PERFIL_VALIDO) {
            estadoPerfil = FALHA;
        }
    } catch (DominioException &e) {
        estadoPerfil = FALHA;
    }
}

/**
 * @brief Testa a rejeição de um valor inválido.
 * - Verifica se setPerfil() lança exceção.
 * - Verifica se o valor inválido não foi armazenado.
*/

void TUPerfil::testarCenarioInvalidoPerfil() {
    try {
        perfil->setPerfil(PERFIL_INVALIDO);
        estadoPerfil = FALHA;
    } catch (DominioException &e) {
        if (perfil->getPerfil() == PERFIL_INVALIDO) {
            estadoPerfil = FALHA;
        }
    }
}

/**
 * @brief Executa o conjunto completo de testes.
 * @return int `SUCESSO` (0) se todos os testes passarem, `FALHA` (-1) caso contrário.
 */

int TUPerfil::runPerfil() {
    setUpPerfil();              // Prepara ambiente de teste
    testarCenarioValidoPerfil();   // Executa teste válido
    testarCenarioInvalidoPerfil(); // Executa teste inválido
    tearDownPerfil();           // Limpa recursos
    return estadoPerfil;        // Retorna resultado dos testes
}
