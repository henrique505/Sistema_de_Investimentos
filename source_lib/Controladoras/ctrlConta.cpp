// ctrlConta.cpp
#include "ctrlConta.hpp"

void CtrlConta::setCntr(ILNConta *cntr) {
    servico = cntr;
}

void CtrlConta::menu(const CPF &cpf) {
    int opcao;
    do {
        std::cout << "\n--- MENU CONTA ---\n";
        std::cout << "1 - Visualizar conta\n";
        std::cout << "2 - Editar conta\n";
        std::cout << "3 - Excluir conta\n";
        std::cout << "0 - Logout\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        if (opcao == 1) {
            try {
                Conta conta = servico->ler(cpf);
                std::cout << "Nome: " << conta.getNome().getNome() << "\n";
            } catch (const std::exception &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        } else if (opcao == 2) {
            std::string nomeStr;
            std::cout << "Novo Nome: ";
            std::getline(std::cin, nomeStr);
            try {
                Nome nome;
                nome.setNome(nomeStr);

                Conta conta;
                conta.setCpf(cpf);
                conta.setNome(nome);

                if (servico->editar(conta))
                    std::cout << "Conta atualizada com sucesso.\n";
                else
                    std::cout << "Falha ao atualizar conta.\n";
            } catch (const std::exception &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        } else if (opcao == 3) {
            try {
                if (servico->excluir(cpf))
                    std::cout << "Conta excluída com sucesso.\n";
                else
                    std::cout << "Falha ao excluir conta.\n";
                break;
            } catch (const std::exception &e) {
                std::cerr << "Erro: " << e.what() << std::endl;
            }
        }

    } while (opcao != 0);
}

void CtrlConta::criar() {
    std::string cpfStr, nomeStr;
    std::cout << "CPF: "; std::getline(std::cin, cpfStr);
    std::cout << "Nome: "; std::getline(std::cin, nomeStr);

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

void CtrlConta::editar() {
    std::string cpfStr, nomeStr;
    std::cout << "CPF da conta a editar: "; std::getline(std::cin, cpfStr);
    std::cout << "Novo Nome: "; std::getline(std::cin, nomeStr);

    try {
        CPF cpf; cpf.setCPF(cpfStr);
        Nome nome; nome.setNome(nomeStr);

        Conta conta;
        conta.setCpf(cpf);
        conta.setNome(nome);

        if (servico->editar(conta))
            std::cout << "Conta atualizada.\n";
        else
            std::cout << "Falha ao atualizar conta.\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlConta::excluir() {
    std::string cpfStr;
    std::cout << "CPF da conta a excluir: "; std::getline(std::cin, cpfStr);

    try {
        CPF cpf; cpf.setCPF(cpfStr);

        if (servico->excluir(cpf))
            std::cout << "Conta excluida.\n";
        else
            std::cout << "Falha ao excluir conta.\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}

void CtrlConta::ler() {
    std::string cpfStr;
    std::cout << "CPF da conta a visualizar: "; std::getline(std::cin, cpfStr);

    try {
        CPF cpf; cpf.setCPF(cpfStr);
        Conta conta = servico->ler(cpf);

        std::cout << "Nome: " << conta.getNome().getNome() << "\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << std::endl;
    }
}
