#include "Caixa.hpp"
#include <iostream>

Caixa::Caixa(Cpf cpf, std::string nome, DiaDaSemana diaDoPagamento, float salario)
	:Funcionario(cpf, nome, salario, diaDoPagamento)
{
}

float Caixa::bonificacao() const
{
	return recuperaSalario() * float(0.1);
}