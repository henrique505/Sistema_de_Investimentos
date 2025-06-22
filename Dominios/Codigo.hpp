//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

#ifndef CODIGO_HPP
#define CODIGO_HPP

#include <stdexcept> // biblioteca onde esta contida a  calsse base runtime_error
#include <string>
#include "DominioException.hpp"

class Codigo {
    private:
        std::string numeroCodigo;
        void validarCodigo(const std::string& codigoInserido);
    public:
        void setCodigo(const std::string& novoCodigo); // "escreve/muda" o conteudo do atributo numeroCodigo
 	   inline std::string getCodigo() const {
 	       return numeroCodigo;
 	   } // "retorna" uma copia do atributo numeroCodigo
};

#endif
