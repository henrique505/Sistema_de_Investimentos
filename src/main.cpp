#include <iostream>
#include "Dominios.hpp"
#include "TUDominios.hpp"
#include "TUEntidades.hpp"
#include "ctrlAutenticacao.hpp"
#include "ctrlConta.hpp"
#include "servicoAutenticacao.hpp"
#include "servicoConta.hpp"

int main() {
    CtrlAutenticacao ctrlAut;
    ServicoAutenticacao servAut;

    CtrlConta ctrlConta;
    ServicoConta servConta;

    // Injetar serviços
    ctrlAut.setCntr(&servAut);
    ctrlAut.setCtrlConta(&servConta);    // serviço de conta
    ctrlAut.setCtrlConta(&ctrlConta);    // controlador de conta <-- ESSENCIAL

    ctrlConta.setCntr(&servConta);       // conectar serviço ao controlador de conta

    ctrlAut.menu(); // inicia menu

    return 0;
}
