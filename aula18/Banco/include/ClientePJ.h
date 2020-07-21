#ifndef CLIENTEPJ_H
#define CLIETNEPJ_H

#include "../include/Cliente.h"
#include <string>

using namespace std;

class ClientePJ : public Cliente{
    private:
    string razaoSocial;
    string cnpj;

    public:
    ClientePJ();
    void setRazaoSocial(string razaoSocial);
    string getRazaoSocial();
    void setCnpj(string cnpj);
    string getCnpj();
    

};





#endif