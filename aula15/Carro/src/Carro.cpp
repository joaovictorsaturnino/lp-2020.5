#include "../include/Carro.h"

Carro::Carro(string cor){
    this->cor = cor;
    this->qtdCarros += qtdCarros;
}

Carro::Carro(){
    this->cor = "Branco";
    this->qtdCarros += qtdCarros;
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