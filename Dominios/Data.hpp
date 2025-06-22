//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840
#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include "DominioException.hpp"


class Data {
private:
    int dia;
    int mes;
    int ano;

    // Metodo para validar a data
    void validarData(int d, int m, int a) const;

public:

    // Metodos de modificacao
    void setData(int d, int m, int a);
    void setData(const std::string& dataString);

    // Metodos de acesso
    int getDia() const;
    int getMes() const;
    int getAno() const;

    // Metodos utilitarios
    std::string getData() const;
};

#endif // DATA_HPP
