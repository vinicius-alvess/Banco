#pragma once
#include "Funcionario.hpp"
#include "DiaDaSemana.hpp"

class Caixa final
	:public Funcionario
{
	public:
		Caixa(Cpf cpf, std::string nome, DiaDaSemana diaDoPagamento, float salario);
		float bonificacao() const;
};

