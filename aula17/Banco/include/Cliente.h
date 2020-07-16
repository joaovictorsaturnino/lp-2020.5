#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

using namespace std;

class Cliente{
    private:
    string nome;
    string cpf;
    static int qtdClientes;

    public:
    Cliente();
    ~Cliente();
    void setNome(string nome);
    string getNome();
    void setCpf(string cpf);
    string getCpf();
};

#endif