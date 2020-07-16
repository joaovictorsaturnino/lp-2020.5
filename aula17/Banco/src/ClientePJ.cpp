#include <iostream>
#include "../include/ClientePJ.h"

using namespace std;

ClientePJ::ClientePJ(){

}


void ClientePJ::setRazaoSocial(string razaoSocial){
    this->razaoSocial = razaoSocial;
}

string ClientePJ::getRazaoSocial(){
    return this->razaoSocial;
}
void ClientePJ::setCnpj(string cnpj){
    this->cnpj = cnpj;
}
string ClientePJ::getCnpj(){
    return this->cnpj;
}