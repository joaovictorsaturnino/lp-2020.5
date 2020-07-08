#include "../include/Conta.h"


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