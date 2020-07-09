#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente{
    public:
    string nome;
    string cpf;
    static int qtdClientes;

    Cliente();
    ~Cliente();
};

#endif