#include "Gerente.hpp"
#include <iostream>

Gerente::Gerente(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento, std::string senha)
	:Funcionario(cpf, nome, salario, diaDoPagamento), Autenticavel(senha)
{
}

float Gerente::bonificacao() const
{
	return recuperaSalario() * float(0.5);
}