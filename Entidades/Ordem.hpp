#ifndef ORDEM_HPP
#define ORDEM_HPP

#include "Dominios.hpp"

class Ordem {
private:
	Codigo codigo;
	CodigoNegociacao codigoNegociacao;
	Data data;
	Dinheiro preco;
	Quantidade quantidade;

public:
	void setCodigo(const Codigo& novoCodigo);
	void setCodigoNegociacao(const CodigoNegociacao& novoCodigoNegociacao);
	void setData(const Data& novaData);
	void setDinheiro(const Dinheiro& novoPreco);
	void setQuantidade(const Quantidade& novaQuantidade);

	Codigo getCodigo() const {
		return codigo;
	}
	CodigoNegociacao getCodigoNegociacao() const {
		return codigoNegociacao;
	}
	Data getData() const {
		return data;
	}
	Dinheiro getDinheiro() const {
		return preco;
	}
	Quantidade getQuantidade() const {
		return quantidade;
	}

};
#endif //ORDEM_HPP
