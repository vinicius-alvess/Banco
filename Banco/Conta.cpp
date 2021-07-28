#include "Conta.hpp"
#include <iostream>

int Conta::numeroDeContas = 0;

Conta::Conta(std::string numero, Titular titular) :
    numero(numero),
    titular(titular),
    saldo(0)
{
    numeroDeContas++;
}

Conta::~Conta()
{
    numeroDeContas--;
}

void Conta::sacar(float valorASacar)
{
    if (valorASacar < 0) {
        std::cout << "Não pode sacar valor negativo" << std::endl;
        return;
    }

    float tarifaDeSaque = valorASacar * taxaDeSaque();
    float valorTotal = valorASacar + tarifaDeSaque;

    if (valorTotal > saldo) {
        std::cout << "Saldo insuficiente" << std::endl;
        return;
    }

    saldo -= valorTotal;
}

void Conta::depositar(float valorADepositar)
{
    if (valorADepositar < 0) {
        std::cout << "Não pode sacar valor negativo" << std::endl;
        return;
    }

    saldo += valorADepositar;
}

void Conta::transferePara(Conta& destino, float valor)
{
    sacar(valor);
    destino.depositar(valor);
}

float Conta::recuperaSaldo() const
{
    return saldo;
}

int Conta::recuperaNumeroDeContas()
{
    return numeroDeContas;
}