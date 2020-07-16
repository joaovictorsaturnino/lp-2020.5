#include "../include/Carro.h"

Carro::Carro(string cor){
    this->cor = cor;
    //this->qtdCarros += 1;
}

Carro::Carro(){
    this->cor = "Branco";
    //this->qtdCarros += 1;
}

void Carro::acelera(int velocidade){
    this->velocidade += velocidade;
}

void Carro::freia(int velocidade){
    this->velocidade -= velocidade;
}

void Carro::ligaCarro(){
    motor.partida();
}