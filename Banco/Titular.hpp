#pragma once
#include <string>
#include "Pessoa.hpp"
#include "Cpf.hpp"
#include "Autenticavel.hpp"

class Titular
	:public Pessoa, public Autenticavel
{
	public:
		Titular(Cpf cpf, std::string nome, std::string senha);
		std::string recuperaCpf() const;
		std::string recuperaNome() const;
};