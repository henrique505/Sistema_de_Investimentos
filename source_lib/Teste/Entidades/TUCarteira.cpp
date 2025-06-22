#include "TUCarteira.hpp"


void TUCarteira::setUpCarteira() {
    carteira = new Carteira();
    estadoCarteira = SUCESSO;
}

void TUCarteira::tearDownCarteira() {
    delete carteira;
}

void TUCarteira::testarCenarioValidoCarteira() {
    Codigo codigo;
    Nome nome;
    Perfil perfil;

    codigo.setCodigo(CODIGO_VALIDO);
    nome.setNome(NOME_VALIDO);
    perfil.setPerfil(PERFIL_VALIDO);

    carteira->setCodigo(codigo);
    carteira->setNome(nome);
    carteira->setPerfil(perfil);

    // Verifica se os valores foram armazenados corretamente
    if (carteira->getCodigo().getCodigo() != CODIGO_VALIDO ||
        carteira->getNome().getNome() != NOME_VALIDO ||
        carteira->getPerfil().getPerfil() != PERFIL_VALIDO) {
        estadoCarteira = FALHA;
        }

}

int TUCarteira::runCarteira() {
    setUpCarteira();
    testarCenarioValidoCarteira();
    tearDownCarteira();
    return estadoCarteira;
}