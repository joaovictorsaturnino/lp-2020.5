#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>
#include <vector>
using namespace std;

class Produto{
    public:
        int codigo;
        string unidadeMedida;
        string nome;
        double preco;
        int quantidade;

        
        Produto();
        ~Produto();
};

#endif