//
// Criado por Gabriel em 03/04/2025.
// Matricula: 241038942

#ifndef CPF_HPP
#define CPF_HPP
 
#include <string>
#include <stdexcept> // biblioteca onde esta contida a  calsse base runtime_error 
#include "DominioException.hpp"
 
class CPF {
 private:
 	std::string numeroCpf;
 	void validar(const std::string& cpfInserido);
 	bool validarDigitosVerificadores(const std::string& cpf);
 public:
 	void setCPF(const std::string& novoCpf); // "escreve/muda" o conteudo do atributo numeroCpf
 	inline std::string getCPF() const { 
 	    return numeroCpf; 
 	} // "retorna" uma copia do atributo numeroCpf
};
 
 
#endif
