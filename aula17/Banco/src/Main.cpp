#include <iostream>
#include "../include/Conta.h"
#include "../include/Cliente.h"
#include "../include/Fila.h"
#include "../include/ClientePJ.h"
#include <iostream>

using namespace std;

int main(){
        
    ClientePJ a;
    ClientePJ b;
    ClientePJ c;
    ClientePJ d;

    Cliente c1;
    Cliente c2;
    Cliente c3;
    Cliente c4;


    a.setRazaoSocial("12343");
    b.setRazaoSocial("124345234");
    c.setRazaoSocial("23424352");
    d.setRazaoSocial("234234234");

    c1.setNome("João");
    c2.setNome("Maria");
    c3.setNome("José");
    c4.setNome("Ester");


    Fila<ClientePJ> filaPessoaJuridica(4);
    filaPessoaJuridica.push(a);
    filaPessoaJuridica.push(b);
    filaPessoaJuridica.push(c);
    filaPessoaJuridica.push(d);

    Fila<Cliente> filaPessoaFisica(4);
    filaPessoaFisica.push(c1);
    filaPessoaFisica.push(c2);
    filaPessoaFisica.push(c3);
    filaPessoaFisica.push(c4);

    return 0;
}
