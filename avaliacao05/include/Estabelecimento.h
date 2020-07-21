#ifndef ESTABELECIMENTO_H
#define ESTABELECIMENTO_H 

#include "../include/Produto.h"
#include <vector>
using namespace std;

class Estabelecimento{
    public:
        vector<Produto> produtos;
        static double totalVendas;
        Estabelecimento();
        ~Estabelecimento();
        void listar();
        void venda(int codigo);
        void caixa();
        Produto procurarProduto(int cod);
        void reabastecer();
};



#endif 