// ctrlAutenticacao.cpp
#include "ctrlAutenticacao.hpp"
#include "servicoConta.hpp"
#include "ctrlConta.hpp"
#include "utils.hpp"


void CtrlAutenticacao::setCntr(ILNAutenticacao *cntr) {
    servico = cntr;
}

void CtrlAutenticacao::setCtrlConta(ILNConta *cntrConta) {
    servicoConta = cntrConta;
}
void CtrlAutenticacao::setCtrlConta(IUConta *cntrConta) {
    ctrlConta = cntrConta;
}

bool CtrlAutenticacao::autenticar() {
    std::string entradaCpf, entradaSenha;

    std::cout << "Digite CPF: ";
    std::getline(std::cin, entradaCpf);

    std::cout << "Digite Senha: ";
    std::getline(std::cin, entradaSenha);

    try {
        CPF cpf;
        cpf.setCPF(entradaCpf);

        Senha senha;
        senha.setSenha(entradaSenha);

        if (servico->autenticar(cpf, senha)) {
            std::cout << "\nAutenticado com sucesso!\n";
            if (servicoConta && ctrlConta) {
                auto *ctrlReal = dynamic_cast<CtrlConta *>(ctrlConta);
                if (ctrlReal) {
                    ctrlReal->menu(cpf);
                } else {
                    std::cerr << "Erro interno: ctrlConta não é CtrlConta*.\n";
                }
            }
            return true;
        } else {
            std::cout << "CPF ou senha incorretos.\n";
            return false;
        }
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
        return false;
    }
}


void CtrlAutenticacao::menu() {
    int opcao;
    do {
        std::cout << "\n--- MENU AUTENTICACAO ---\n";
        std::cout << "1 - Login\n";
        std::cout << "2 - Registrar usuario\n";
        std::cout << "0 - Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        if (opcao == 1) {
            autenticar();
        } else if (opcao == 2) {
            std::string entradaCpf, entradaSenha, entradaNome, entradaPerfil;
            std::cout << "Digite o seu CPF: ";
            std::getline(std::cin, entradaCpf);
            std::cout << "Digite sua senha: ";
            std::getline(std::cin, entradaSenha);
            std::cout << "Digite o seu nome: ";
            std::getline(std::cin, entradaNome);

            try {
                CPF cpf;
                Senha senha;
                Nome nome;

                cpf.setCPF(entradaCpf);
                senha.setSenha(entradaSenha);
                nome.setNome(entradaNome);


                servico->registrar(cpf, senha, nome);

                Conta conta;
                conta.setCpf(cpf);
                conta.setNome(nome);
                conta.setSenha(senha);

                if (servicoConta) {
                    if (!servicoConta->criar(conta))
                        std::cout << "Conta registrada com sucesso!\n";
                    else {
                        std::cerr << "Falha ao registrar conta.\n";
                    }
                }

            } catch (const std::exception &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }
    } while (opcao != 0);
}
