#include <iostream>
#include "Dominios.hpp"
#include "TUDominios.hpp"
#include "TUEntidades.hpp"
using namespace std;

int main()
{
    TUCodigo codigo;
    TUCodigoNegociacao negociacao;
    TUCpf cpf;
    TUData data;
    TUDinheiro dinheiro;
    TUNome nome;
    TUPerfil perfil;
    TUQuantidade quant;
    TUSenha senha;

    cout << "\n********************TESTE DOS DOMINIOS************************\n";

    cout << "Teste do dominio Dinheiro: " << codigo.runCodigo() << endl;
    cout << "Teste do dominio CodigoNegociacao: " << negociacao.runCodigoNegociacao() << endl;
    cout << "Teste do dominio CPF: " << cpf.runCpf() << endl;
    cout << "Teste do dominio Data: " << data.runData() << endl;
    cout << "Teste do dominio Dinheiro: " << dinheiro.runDinheiro() << endl;
    cout << "Teste do dominio Nome: " << nome.runNome() << endl;
    cout << "Teste do dominio Perfil: " << perfil.runPerfil() << endl;
    cout << "Teste do dominio Quantidade: " << quant.runQuantidade() << endl;
    cout << "Teste do dominio Senha: " << senha.runSenha() << endl;


    cout << "\n********************TESTE DAS ENTIDADES***********************\n";

    TUOrdem ordem;
    TUConta conta;
    TUCarteira carteira;

    cout << "Teste da entidade Ordem: " << ordem.runOrdem() << endl;
    cout << "Teste da entidade Conta: " << conta.runConta() << endl;
    cout << "Teste da entidade Carteira: " << carteira.runCarteira() << endl;

    return 0;
}
