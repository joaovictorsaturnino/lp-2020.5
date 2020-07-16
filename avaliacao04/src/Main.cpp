#include "../include/Cliente.h"
#include "../include/Estabelecimento.h"
#include "../include/Produto.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]){
    
    Cliente cliente;
    Estabelecimento estabelecimento;
    Produto produto;    
    int opc;
    double saldo;
    while(opc != 6){
        cout << "================================" << endl;
        cout << "|     Selecione uma opção:     |" << endl;
        cout << "|1.       Adicionar saldo      |" << endl;
        cout << "|2. Verificar produtos da loja |" << endl;
        cout << "|3.      Realizar compra       |" << endl;
        cout << "|4.         Ver sacola         |" << endl;
        cout << "|5.      Finalizar compras     |" << endl;
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
            string nomeProduto;
            cout << "Digite o nome do produto: ";
            cin >> nomeProduto;
            produto.nome = nomeProduto;
            estabelecimento.completarProduto(produto);
            cliente.compra(produto);
            estabelecimento.venda(produto.codigo);
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
                opc = 6;
            }

        }
        
        if(opc > 6){
            cout << "Opção inválida" << endl;
        }

     }
    
    return 0;
}
