#include <iostream>
#include "Dominios.hpp"
#include "TUDominios.hpp"
#include "TUEntidades.hpp"
#include "ctrlAutenticacao.hpp"
#include "ctrlConta.hpp"
#include "servicoAutenticacao.hpp"
#include "servicoConta.hpp"
#include "ctrlCarteira.hpp"
#include "servicoCarteira.hpp"

int main() {
    // Autenticacao
    CtrlAutenticacao ctrlAut;
    ServicoAutenticacao servAut;

    // Conta
    CtrlConta ctrlConta;
    ServicoConta servConta;

    // Carteira
    ServicoCarteira servCarteira;
    CtrlCarteira ctrlCarteira(&servCarteira);

    // Injecao de dependencias
    ctrlAut.setCntr(&servAut);
    ctrlAut.setCtrlConta(&servConta);   // serviço
    ctrlAut.setCtrlConta(&ctrlConta);   // controlador
    ctrlConta.setCntr(&servConta);
    ctrlConta.setCtrlCarteira(&ctrlCarteira);

    // Menu inicial
    ctrlAut.menu();

    return 0;
}
