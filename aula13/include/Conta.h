#ifndef CONTA_H
#define CONTA_H

#include <string>

using namespace std;

class Conta{

    public:
    int numero;
    string titular;
    double saldo;

    void saca(double valor);
    void deposita(double valor);
    void transfere(double valor, Conta& conta);
};


#endif
