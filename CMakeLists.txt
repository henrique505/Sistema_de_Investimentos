cmake_minimum_required(VERSION 3.10)
project(Sistema_de_Investimentos)

set(CMAKE_CXX_STANDARD 17)

include_directories(Dominios)
include_directories(Entidades)
include_directories(Testes)
include_directories(Testes/Dominios)
include_directories(Testes/Entidades)
include_directories(Servicos)
include_directories(Interfaces)
include_directories(Controladoras)


include_directories(${CMAKE_SOURCE_DIR}/external/sqlite)
include_directories(${CMAKE_SOURCE_DIR}/external)

add_library(sqlite3 STATIC external/sqlite/sqlite3.c
        Controladoras/ctrlAutenticacao.hpp
        source_lib/Controladoras/ctrlConta.cpp
        Servicos/servicoCarteira.hpp
        Controladoras/ctrlCarteira.hpp
        source_lib/Controladoras/ctrlCarteira.cpp
        Servicos/servicoOrdem.hpp)

add_executable(Sistema_de_Investimentos
    Dominios/Codigo.hpp
    Dominios/CodigoNegociacao.hpp
    Dominios/Cpf.hpp
    Dominios/Data.hpp
    Dominios/Dinheiro.hpp
    Dominios/DominioException.hpp
    Dominios/Dominios.hpp
    Dominios/Nome.hpp
    Dominios/Perfil.hpp
    Dominios/Quantidade.hpp
    Dominios/Senha.hpp
    Entidades/Carteira.hpp
    Entidades/Conta.hpp
    Entidades/Ordem.hpp
    source_lib/Dominios/Codigo.cpp
    source_lib/Dominios/CodigoNegociacao.cpp
    source_lib/Dominios/Cpf.cpp
    source_lib/Dominios/Data.cpp
    source_lib/Dominios/Dinheiro.cpp
    source_lib/Dominios/Dominios.cpp
    source_lib/Dominios/Nome.cpp
    source_lib/Dominios/Perfil.cpp
    source_lib/Dominios/Quantidade.cpp
    source_lib/Dominios/Senha.cpp
    source_lib/Entidades/Carteira.cpp
    source_lib/Entidades/Conta.cpp
    source_lib/Entidades/Ordem.cpp
    source_lib/Teste/Dominios/TUCodigo.cpp
    source_lib/Teste/Dominios/TUCodigoNegociacao.cpp
    source_lib/Teste/Dominios/TUCpf.cpp
    source_lib/Teste/Dominios/TUData.cpp
    source_lib/Teste/Dominios/TUDinheiro.cpp
    source_lib/Teste/Dominios/TUNome.cpp
    source_lib/Teste/Dominios/TUPerfil.cpp
    source_lib/Teste/Dominios/TUQuantidade.cpp
    source_lib/Teste/Dominios/TUSenha.cpp
    source_lib/Teste/Entidades/TUCarteira.cpp
    source_lib/Teste/Entidades/TUConta.cpp
    source_lib/Teste/Entidades/TUOrdem.cpp
    src/main.cpp
    Testes/Dominios/TUCodigo.hpp
    Testes/Dominios/TUCodigoNegociacao.hpp
    Testes/Dominios/TUCpf.hpp
    Testes/Dominios/TUData.hpp
    Testes/Dominios/TUDinheiro.hpp
    Testes/Dominios/TUNome.hpp
    Testes/Dominios/TUPerfil.hpp
    Testes/Dominios/TUQuantidade.hpp
    Testes/Dominios/TUSenha.hpp
    Testes/Entidades/TUCarteira.hpp
    Testes/Entidades/TUConta.hpp
    Testes/Entidades/TUOrdem.hpp
        Testes/Dominios/TUDominios.hpp
        Testes/Entidades/TUEntidades.hpp
        Interfaces/interfaces.hpp
        Entidades/Entidades.hpp
        Servicos/servicoAutenticacao.hpp
        source_lib/Servicos/servicoAutenticacao.cpp
        Controladoras/ctrlAutenticacao.hpp
        source_lib/Controladoras/ctrlAutenticacao.cpp
        Servicos/servicoConta.hpp
        source_lib/Servicos/servicoConta.cpp
        Controladoras/ctrlConta.hpp
        source_lib/Controladoras/ctrlConta.cpp
        Servicos/servicoCarteira.hpp
        source_lib/Servicos/servicoCarteira.cpp
        Controladoras/ctrlCarteira.hpp
        source_lib/Controladoras/ctrlCarteira.cpp
        external/utils.hpp
        Servicos/servicoOrdem.hpp
        source_lib/Servicos/servicoOrdem.cpp
)
target_link_libraries(Sistema_de_Investimentos PRIVATE sqlite3)
