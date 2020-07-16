#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "../include/Empresa.h"

#include <string>

using namespace std;

class Funcionario{
    private:
        string nome;
        Empresa empresa;
        string departamento;
        double salario;
        string dataAdmissao;

};

#endif