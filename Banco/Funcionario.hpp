#pragma once
#include "Cpf.hpp"
#include "Pessoa.hpp"
#include "DiaDaSemana.hpp"
#include <string>

class Funcionario:public Pessoa
{
    private:
        float salario;
        //0 = Domingo, 1 = Segunda...
        DiaDaSemana diaDoPagamento;

    public:
        Funcionario(Cpf cpf, std::string nome, float salario, DiaDaSemana diaDoPagamento);
        std::string recuperaCpf() const;
        std::string recuperaNome() const;
        float recuperaSalario() const;
        virtual float bonificacao() const = 0;
};