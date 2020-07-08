#ifndef CONTA_H
#define CONTA_H

#include "../include/Cliente.h"
#include "../include/Agencia.h"
#include <string>

using namespace std;

class Conta{

    public:
    int numero;
    Agencia agencia;
    Cliente titular;
    double saldo;

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta& conta);
};


#endif
