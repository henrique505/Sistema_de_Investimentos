#include "ctrlConta.hpp"
#include "utils.hpp"

#include <limits>

void CtrlConta::setCntr(ILNConta *cntr) {
    servico = cntr;
}

void CtrlConta::setCtrlCarteira(CtrlCarteira *cntrCarteira) {
    ctrlCarteira = cntrCarteira;
}

void CtrlConta::setServicoCarteira(ServicoCarteira *servicoCarteira) {
    this->servicoCarteira = servicoCarteira;
}

void CtrlConta::menu(const CPF &cpf) {
    int opcao;
    do {
        std::cout << "\n--- MENU CONTA ---\n";
        std::cout << "1 - Gerenciar carteiras\n";
        std::cout << "2 - Visualizar conta\n";
        std::cout << "3 - Editar conta\n";
        std::cout << "4 - Excluir conta\n";
        std::cout << "0 - Logout\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        if (opcao == 1) {
            if (ctrlCarteira) ctrlCarteira->menu(cpf);
        } else if (opcao == 2) {
            try {
                Conta conta = servico->ler(cpf);
                std::cout << "CPF: " << cpf.getCPF() << "\n";
                std::cout << "Nome: " << conta.getNome().getNome() << "\n";

                if (servicoCarteira) {
                    auto lista = servicoCarteira->listarCarteirasPor(cpf);
                    std::cout << "Total de carteiras: " << lista.size() << "\n";
                    for (const auto &c : lista) {
                        std::cout << "- [" << c.getCodigo().getCodigo() << "] "
                                  << c.getNome().getNome() << " - "
                                  << c.getPerfil().getPerfil() << "\n";
                    }
                }
            } catch (const std::exception &e) {
                std::cerr << "Erro: " << e.what() << "\n";
            }
        } else if (opcao == 3) {
            editar(cpf);
        } else if (opcao == 4) {
            excluir(cpf);
            break;
        }

    } while (opcao != 0);
}

void CtrlConta::criar() {
    std::string cpfStr, nomeStr;
    std::cout << "CPF: ";
    std::getline(std::cin, cpfStr);
    std::cout << "Nome: ";
    std::getline(std::cin, nomeStr);

    try {
        CPF cpf; cpf.setCPF(cpfStr);
        Nome nome; nome.setNome(nomeStr);

        Conta conta;
        conta.setCpf(cpf);
        conta.setNome(nome);

        if (servico->criar(conta))
            std::cout << "Conta criada com sucesso.\n";
        else
            std::cout << "Falha ao criar conta.\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlConta::editar(const CPF &cpf) {
    int opcao;
    std::cout << "\n--- EDITAR CONTA ---\n";
    std::cout << "1 - Editar nome\n";
    std::cout << "2 - Editar senha\n";
    std::cout << "3 - Editar ambos\n";
    std::cout << "0 - Cancelar\n";
    std::cout << "Escolha: ";
    std::cin >> opcao;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (opcao == 0) {
        std::cout << "Edição cancelada.\n";
        return;
    }

    Conta conta;
    conta.setCpf(cpf);  // sempre define o CPF

    try {
        if (opcao == 1 || opcao == 3) {
            std::string nomeStr;
            std::cout << "Novo Nome: ";
            std::getline(std::cin, nomeStr);
            Nome nome; nome.setNome(nomeStr);
            conta.setNome(nome);
        }

        if (opcao == 2 || opcao == 3) {
            std::string senhaStr;
            std::cout << "Nova Senha: ";
            std::getline(std::cin, senhaStr);
            Senha senha; senha.setSenha(senhaStr);
            conta.setSenha(senha);
        }

        if (servico->editar(conta)) {
            std::cout << "Conta atualizada.\n";
        } else {
            std::cout << "Falha ao atualizar conta.\n";
        }

    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}


void CtrlConta::excluir(const CPF &cpf) {
    try {
        if (servico->excluir(cpf))
            std::cout << "Conta excluída.\n";
        else
            std::cout << "Falha ao excluir conta.\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlConta::ler() {
    std::string cpfStr;
    std::cout << "CPF da conta a visualizar: ";
    std::getline(std::cin, cpfStr);

    try {
        CPF cpf; cpf.setCPF(cpfStr);
        Conta conta = servico->ler(cpf);

        std::cout << "Nome: " << conta.getNome().getNome() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}
