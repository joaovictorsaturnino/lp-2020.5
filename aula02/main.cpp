#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string mensagem;

    if(argc == 1){
        cout << "Uso: " << argv[0] << " add <message>" << endl;
        return -1;
    }

    if(argc == 2){
        cout << "Escreva uma mensagem: " << endl;
        getline(cin, mensagem);
        cout << "Mensagem Adicionada" << endl;
    }

    if(argc == 3){
        cout << "Mensagem Adicionada" << endl;
    }
    
    return 0;
}
