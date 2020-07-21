#include "../include/Estabelecimento.h"
#include "../include/Produto.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

double Estabelecimento::totalVendas;

Estabelecimento::Estabelecimento(){
    string line;
    string tipo;
    ifstream file_read("estoque.csv");
    ofstream file_write("estoque.csv", ios::app);
    
    if (file_read.fail()) {
        cout << "Arquivo não encontrado" << endl;
    }

    else {
        while(!file_read.eof()){
            Produto p;
            p.nome = "aa";
            getline(file_read,line);

            stringstream stream(line);

            string delimitador = ",";

            auto start = 0U;
            auto end = line.find(delimitador);
            int index = 0;

            while (end != string::npos){
                if (index == 0) {
                    p.codigo = stoi(line.substr(start, end - start));
                }

                if (index == 1) {
                    p.nome = line.substr(start, end - start);   
                }
                
                if (index == 2) {
                    p.unidadeMedida = line.substr(start, end - start);
                } 

                if (index == 3) {
                    auto start2 = 0U;
                    string delimitador2 = " ";
                    auto end2 = line.find(delimitador2);

                    while (end2 != string::npos){
                        start2 = end2 + delimitador2.length();
                        end2 = line.find(delimitador2, start2);
                    }
                    string line2 = line.substr(start2, end2 - start2);
                    size_t aspas = line2.find("\"");

                    double preco = stod(line2.substr(0, aspas));

                    p.preco = preco;
                }
                start = end + delimitador.length();
                end = line.find(delimitador, start);
                index++;
            }

            produtos.push_back(p);
        }
    }
}

Estabelecimento::~Estabelecimento(){

}

void Estabelecimento::listar(){
   cout << "cod, nome, preco, unidade de medida " << endl; 
    for(int i = 0; i < produtos.size(); i++){
        cout << produtos[i].codigo << " ";
        cout << produtos[i].nome << " ";
        cout << produtos[i].preco << " ";
        cout << produtos[i].unidadeMedida;
        cout << "---------------------" << endl;
    }
}

Produto Estabelecimento::procurarProduto(int cod){
    for(auto const& prod: this->produtos){
        if (prod.codigo == cod) {
            return prod;
        }
    }
}

void Estabelecimento::venda(int codigo){
    ofstream caixa ("caixa.csv", ios::app);
    int quantidadeProduto;
    cout << codigo << endl;
    double valorCompra = 0;
    cout << "Informe quantas unidades desse produto vc deseja comprar: ";
    cin >> quantidadeProduto;

    for(int i = 0; i < produtos.size(); i++){
        if(produtos[i].codigo == codigo){
            if(produtos[i].quantidade > quantidadeProduto){
                cout << "Produto " << produtos[i].nome << " comprado com sucesso" << endl;
                produtos[i].quantidade = produtos[i].quantidade - quantidadeProduto;
                valorCompra = produtos[i].preco * quantidadeProduto;
                totalVendas += valorCompra;
                caixa << produtos[i].codigo << " ";
                caixa << produtos[i].nome << " ";
                caixa << quantidadeProduto << " ";
                caixa << valorCompra << endl;
            }else{
                cout << "Desculpe, não possuimos esta quantidade do produto em estoque." << endl;
                cout << "Estoque atual do produto: " << produtos[i].quantidade << endl;
            }
        }
    }
}

void Estabelecimento::caixa(){
    ifstream leituraCaixa("caixa.csv");
    string linha;
    while(!leituraCaixa.eof()){
        getline(leituraCaixa, linha);
        cout << linha << endl;
    }
    cout << "Total de vendas:" << totalVendas << endl;
}

// void Estabelecimento::preencherVector(){
//     Produto p1;
//     Produto p2;
//     Produto p3;
//     Produto p4;
//     Produto p5;
//     Produto p6;
//     Produto p7;
//     Produto p8;
//     Produto p9;
//     Produto p10;
//     Produto p11;
//     Produto p12;
//     Produto p13;
//     Produto p14;
//     Produto p15;
//     Produto p16;
//     Produto p17;

//     p1.codigo = 1;
//     p1.nome = "Feijão";
//     p1.unidadeMedida = "Pacote";
//     p1.preco = 6.20;
//     p1.quantidade = 10;
//     produtos.push_back(p1);

//     p2.codigo = 2;
//     p2.nome = "Arroz";
//     p2.unidadeMedida = "Pacote";
//     p2.preco = 3.40;
//     p2.quantidade = 23;
//     produtos.push_back(p2);
    
//     p3.codigo = 3;
//     p3.nome = "Fubá";
//     p3.unidadeMedida = "Pacote";
//     p3.preco = 2.90;
//     p3.quantidade = 50;
//     produtos.push_back(p3);

//     p4.codigo = 4;
//     p4.nome = "Milho verde";
//     p4.unidadeMedida = "Lata";
//     p4.preco = 1.30;
//     p4.quantidade = 10;
//     produtos.push_back(p4);
    
//     p5.codigo = 5;
//     p5.nome = "Ervilha";
//     p5.unidadeMedida = "Lata";
//     p5.preco = 1.30;
//     p5.quantidade = 10;
//     produtos.push_back(p5);
    
//     p6.codigo = 6;
//     p6.nome = "Farinha";
//     p6.unidadeMedida = "Pacote";
//     p6.preco = 2.80;
//     p6.quantidade = 5;
//     produtos.push_back(p6);
    
//     p7.codigo = 7;
//     p7.nome = "Tomate";
//     p7.unidadeMedida = "Quilo";
//     p7.preco = 2.25;
//     p7.quantidade = 8;
//     produtos.push_back(p7);
    
//     p8.codigo = 8;
//     p8.nome = "Laranja";
//     p8.unidadeMedida = "Quilo";
//     p8.preco = 3.50;
//     p8.quantidade = 4;
//     produtos.push_back(p8);
    
//     p9.codigo = 9;
//     p9.nome = "Limão";
//     p9.unidadeMedida = "Quilo";
//     p9.preco = 3.50;
//     p9.quantidade = 4;
//     produtos.push_back(p9);
    
//     p10.codigo = 10;
//     p10.nome = "Macaxeira";
//     p10.unidadeMedida = "Quilo";
//     p10.preco = 4.50;
//     p10.quantidade = 10;
//     produtos.push_back(p10);
    
//     p11.codigo = 11;
//     p11.nome = "Pimentão";
//     p11.unidadeMedida = "Quilo";
//     p11.preco = 3.30;
//     p11.quantidade = 3;
//     produtos.push_back(p11);
    
//     p12.codigo = 12;
//     p12.nome = "Queijo";
//     p12.unidadeMedida = "Quilo";
//     p12.preco = 28.00;
//     p12.quantidade = 8;
//     produtos.push_back(p12);
    
//     p13.codigo = 13;
//     p13.nome = "Presunto";
//     p13.unidadeMedida = "Quilo";
//     p13.preco = 14.00;
//     p13.quantidade = 8;
//     produtos.push_back(p13);
    
//     p14.codigo = 14;
//     p14.nome = "Carne";
//     p14.unidadeMedida = "Quilo";
//     p14.preco = 24.92;
//     p14.quantidade = 5;
//     produtos.push_back(p14);
    
//     p15.codigo = 15;
//     p15.nome = "Salsicha";
//     p15.unidadeMedida = "Quilo";
//     p15.preco = 8.49;
//     p15.quantidade = 15;
//     produtos.push_back(p15);
    
//     p16.codigo = 16;
//     p16.nome = "Peixe";
//     p16.unidadeMedida = "Quilo";
//     p16.preco = 12.45;
//     p16.quantidade = 5;
//     produtos.push_back(p16);
    
//     p17.codigo = 17;
//     p17.nome = "Margarina";
//     p17.unidadeMedida = "Lata";
//     p17.preco = 2.99;
//     p17.quantidade = 10;
//     produtos.push_back(p17);
// }