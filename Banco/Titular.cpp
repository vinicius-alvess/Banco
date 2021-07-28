#include "Titular.hpp"
#include <iostream>

Titular::Titular(Cpf cpf, std::string nome, std::string senha)
	:Pessoa(cpf, nome), Autenticavel(senha)
{
}

std::string Titular::recuperaCpf() const
{
	return cpf.recuperaNumero();
}

std::string Titular::recuperaNome() const
{
	return nome;
}