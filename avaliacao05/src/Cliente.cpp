#include "../include/Cliente.h"
#include "../include/Estabelecimento.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int Cliente::qtdClientes;

Cliente::Cliente(){
    this->qtdClientes +=1;

}


Cliente::~Cliente(){
    
}

void Cliente::compra(Produto produto){
    if (this->saldo >= produto.preco){
        this->saldo -= produto.preco;
        this->sacola.push_back(produto);

    } else {
        cout << "Desculpe, seu saldo é insuficiente" << endl;
    }
}

void Cliente::verSacola(){
    for(int i = 0; i< sacola.size(); i++){
        cout <<"- " << sacola[i].nome << " ";
        cout << sacola[i].quantidade << endl;
    }
}

void Cliente::registro(){
    string nomeArquivo = "cliente_" + to_string(qtdClientes);
    ofstream registroCliente(nomeArquivo+".txt", ios::app);
    for(int i = 0; i < sacola.size(); i++){
        registroCliente << " " + sacola[i].codigo;
        registroCliente << " " + sacola[i].nome + " ";
        registroCliente << sacola[i].preco;
        registroCliente << " " + sacola[i].quantidade;
        registroCliente << " " + sacola[i].unidadeMedida << endl;
    }
}