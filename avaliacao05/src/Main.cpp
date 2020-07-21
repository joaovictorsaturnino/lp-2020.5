#include "../include/Cliente.h"
#include "../include/Estabelecimento.h"
#include "../include/Produto.h"
#include "../include/Fornecedor.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
    
    Cliente cliente;
    Estabelecimento estabelecimento;
    Fornecedor fornecedor;   
    int opc;
    double saldo;
    while(opc != 8){
        cout << "=========*SUPERMERCADO*=========" << endl;
        cout << "|     Selecione uma opção:     |" << endl;
        cout << "|1.       Adicionar saldo      |" << endl;
        cout << "|2. Verificar produtos da loja |" << endl;
        cout << "|3.      Realizar compra       |" << endl;
        cout << "|4.         Ver sacola         |" << endl;
        cout << "|5.      Finalizar compras     |" << endl;
        cout << "|6.Lista produtos do fornecedor|" << endl;
        cout << "|7.    Reabastecer estoque     |" << endl;
        cout << "================================" << endl;
        cout << "opção: ";
        cin >> opc;
    
        if(opc == 1){
            cout << "Digite o novo saldo: ";
            cin >> saldo;
            cliente.saldo = saldo;
            cout << "Saldo de 'R$" << saldo << "' adicionado" << endl;
        }
        if(opc == 2){
            cout << "Listando produtos" << endl;
            estabelecimento.listar();
        }
        if(opc == 3){
            int codigo;
            cout << "Digite o codigo do produto: ";
            cin >> codigo;
            Produto p = estabelecimento.procurarProduto(codigo); 
            p.codigo = codigo;
            cliente.compra(p);
            estabelecimento.venda(p.codigo);
        }
        if(opc == 4){
            cliente.verSacola();
        }
        if(opc == 5){
            int opcao;
            cout << "Digite 1 se deseja iniciar um novo cliente ou 2 se deseja encerrar definitivamente o programa: ";
            cin >> opcao;
            if(opcao == 1){
                cliente.registro();
            } 
            if(opcao == 2){
                opc = 8;
            }

        }
        if(opc == 6){
            fornecedor.listarProdutos();
        }
        if(opc == 7){
            int codigoProd;
            int quantidadeProd;
            cout << "Digite o código do produto que deseja reabastecer: ";
            cin >> codigoProd;
            cout << "Digite a quantidade do produto que deseja reabastecer: ";
            cin >> quantidadeProd;
            fornecedor.repassarProdutos(codigoProd, quantidadeProd);
        }
        
        if(opc > 8){
            cout << "Opção inválida" << endl;
        }

     }
    
    return 0;
}
