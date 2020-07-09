#include "../include/Conta.h"

int Conta::qtdContas;

Conta::Conta(Cliente& titular){
    this -> titular = titular;
    this -> qtdContas += 1;
}

Conta::Conta(){
    this -> qtdContas += 1;
}

void Conta::saca(double valor){
    this->saldo = this->saldo - valor;

}

void Conta::deposita(double valor){
   this->saldo = this->saldo + valor;
   
}

void Conta::transfere(double valor, Conta& conta){
    this->saldo = this->saldo - valor;
    conta.saldo = conta.saldo + valor;
}