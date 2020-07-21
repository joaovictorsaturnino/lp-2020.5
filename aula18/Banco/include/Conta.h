#ifndef CONTA_H
#define CONTA_H

#include "../include/ClientePF.h"
#include "../include/Agencia.h"
#include <string>

using namespace std;

class Conta{

    public:
    int numero;
    Agencia agencia;
    ClientePF titular;
    double saldo;
    static int qtdContas;

    Conta();
    Conta(ClientePF& titular);
    ~Conta();

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta& conta);
};


#endif
