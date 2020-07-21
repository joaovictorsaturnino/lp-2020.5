#ifndef CLIENTE_H
#define CLIENTE_H

#include "../include/Cliente.h"
#include <string>

using namespace std;

class ClientePF : public Cliente{
    private:
    string nome;
    string cpf;
    static int qtdClientes;

    public:
    ClientePF();
    ~ClientePF();
    void setNome(string nome);
    string getNome();
    void setCpf(string cpf);
    string getCpf();
};

#endif