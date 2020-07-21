#include "../include/Fornecedor.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


Fornecedor::Fornecedor(){
    string line;
    string tipo;
    ifstream file_read("fornecedor.csv");
    ofstream file_write("fornecedor.csv", ios::app);
    
    if (file_read.fail()) {
        cout << "Arquivo não encontrado" << endl;
    } else {
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

            produtos.push(p);
        }
    }
}


void Fornecedor::repassarProdutos(int codigo, int quantidade){

}

void Fornecedor::listarProdutos(){
    for(int i = 0; i < produtos.size; i++){
        cout << produtos.elements[i].nome << endl;
    }
}