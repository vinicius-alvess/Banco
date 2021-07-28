#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaPoupanca.hpp"
#include "ContaCorrente.hpp"
#include "Titular.hpp"
#include "Cpf.hpp"
#include "Funcionario.hpp"
#include "Caixa.hpp"
#include "Gerente.hpp"
#include "DiaDaSemana.hpp"

using namespace std;

void ExibeSaldo(const Conta& conta)
{
    cout << "O saldo da conta: " << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta, float valorASaque)
{
    conta.sacar(valorASaque);
}

void RealizaDeposito(Conta& conta, float valorADepositar)
{
    conta.depositar(valorADepositar);
}

void ExibeDadosDoTitular(Titular& titular)
{
    cout << endl;
    cout << "Titular: " << endl;
    cout << "Cpf: " << titular.recuperaCpf() << endl;
    cout << "Nome: " << titular.recuperaNome() << endl;
}

//void ExibeDadosDoFuncionario(Funcionario& funcionario)
//{
//    cout << endl;
//    cout << "Funcionario: " << endl;
//    cout << "Cpf: " << funcionario.recuperaCpf() << endl;
//    cout << "Nome: " << funcionario.recuperaNome() << endl;
//    cout << "Salario: " << funcionario.recuperaSalario() << endl;
//    cout << "Bonificacao: " << funcionario.bonificacao() << endl;
//    cout << endl;
//}

void fazLogin(Autenticavel& alguem, std::string senha)
{
    if (alguem.autentica(senha))
    {
        cout << "Login realizado com sucesso" << endl;
    }
    else {
        cout << "Senha invalida" << endl;
    }
}

int main()
{
    //Cria titular e Conta Poupanca
    Titular titular(Cpf("123.456.789-10"), "Vinicius", "umasenha");
    fazLogin(titular, "umasenha");

    ContaPoupanca umaContaPoupanca("123456", titular);
    RealizaDeposito(umaContaPoupanca, 500);
    RealizaSaque(umaContaPoupanca, 100);
    
    
    // Cria titular e Conta Corrente
    Titular outro(Cpf("098.765.432-10"), "Kemilly", "outrasenha");
    fazLogin(outro, "outrasenha");

    ContaCorrente umaContaCorrente("654321", outro);
    RealizaDeposito(umaContaCorrente, 500);
    RealizaSaque(umaContaCorrente, 100);

    // Realiza Transferencia
    umaContaCorrente.transferePara(umaContaPoupanca, 200);
    umaContaPoupanca.transferePara(umaContaCorrente, 200);

    // Cadastros de funcionarios
    Caixa caixa(Cpf("647.555.620.56"), "Caixa Preta", DiaDaSemana::Terca, 1000);
    Gerente gerente(Cpf("123.456.789-10"), "Gerente Asno", 3000, DiaDaSemana::Quarta, "senhaGerente");
    fazLogin(gerente, "senhaGerente");


    /**** Exibe dados ****/

    cout << "Numero de contas criadas: " << Conta::recuperaNumeroDeContas() << endl;//Exibe numero de contas criadas

    ExibeDadosDoTitular(titular);
    ExibeSaldo(umaContaPoupanca);

    ExibeDadosDoTitular(outro);
    ExibeSaldo(umaContaCorrente);

    ExibeDadosDoFuncionario(caixa);
    ExibeDadosDoFuncionario(gerente);
 
    return 0;
}