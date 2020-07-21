#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include "../include/VectorSupermercado.h"
#include "../include/Produto.h"
#include <string>

using namespace std;

class Fornecedor{
    public:
        VectorSupermercado <Produto> produtos;

        Fornecedor();
        void listarProdutos();
        void repassarProdutos(int codigo, int quantidade);

};


#endif