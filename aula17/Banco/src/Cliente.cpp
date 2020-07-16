#include "../include/Cliente.h"

int Cliente::qtdClientes;

Cliente::Cliente(){
    this->qtdClientes += 1;
}
Cliente::~Cliente(){

}

void Cliente::setNome(string nome){
    this->nome = nome;
}

string Cliente::getNome(){
    return this->nome;
}

void Cliente::setCpf(string cpf){
    this->cpf = cpf;
}

string Cliente::getCpf(){
    return this->cpf;
}