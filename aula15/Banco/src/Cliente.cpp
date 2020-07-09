#include "../include/Cliente.h"

int Cliente::qtdClientes;

Cliente::Cliente(){
    this->qtdClientes += 1;
}
Cliente::~Cliente(){
}