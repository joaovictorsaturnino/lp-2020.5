#ifndef CLIENTE_H
#define CLIENTE_H

#include "../include/Produto.h"
#include <vector>
#include <string>
using namespace std;

class Cliente{
    public:
        double saldo;
        vector<Produto> sacola;
        static int qtdClientes;

    Cliente();
    ~Cliente();
    void compra(Produto produto);
    void verSacola();
    void registro();
};



#endif