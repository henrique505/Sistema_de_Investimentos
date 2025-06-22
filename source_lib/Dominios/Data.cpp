
//
// Criado por Henrique em 04/04/2025.
// Matricula: 241020840

#include "Data.hpp"
#include <sstream>
#include <iomanip>

//Metodo de validacao
void Data::validarData(int d, int m, int a) const {
    if (m < 1 || m > 12) throw DominioException("Mes invalido.");
    if (d < 1 || d > 31) throw DominioException("Dia invalido.");

    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) {
        throw DominioException("Dia invalido para o mes.");
    }

    if (m == 2) {
        bool bissexto = (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
        if (d > (bissexto ? 29 : 28)) {
            throw DominioException("Dia invalido para fevereiro.");
        }
    }
}

// Metodos de modificacao
void Data::setData(int d, int m, int a) {
    validarData(d, m, a);
    dia = d;
    mes = m;
    ano = a;
}

void Data::setData(const std::string& dataString) {
    if (dataString.length() != 8 || dataString.find_first_not_of("0123456789") != std::string::npos) {
        throw DominioException("Data deve estar no formato AAAAMMDD.");
    }

    int a = std::stoi(dataString.substr(0, 4));
    int m = std::stoi(dataString.substr(4, 2));
    int d = std::stoi(dataString.substr(6, 2));

    setData(d, m, a);
}

// Metodos de acesso
int Data::getDia() const { return dia; }
int Data::getMes() const { return mes; }
int Data::getAno() const { return ano; }

// Metodo utilitario
std::string Data::getData() const {
    std::ostringstream dataFormatada;
    dataFormatada << std::setw(4) << std::setfill('0') << ano
        << std::setw(2) << std::setfill('0') << mes
        << std::setw(2) << std::setfill('0') << dia;
    return dataFormatada.str();
}

