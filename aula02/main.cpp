#include <iostream>
#include <string>
using namespace std;

void show_usage(const string &prog_name);

int main(int argc, char const *argv[])
{
    string mensagem;

    if(argc == 1){
        show_usage(argv[0]);
        return -1;
    }

    string action = argv[1];
    
    if(action != "add"){
        show_usage(argv[0]);
        return -1;
    }

    if(argc == 2){
        cout << "Escreva uma mensagem: " << endl;
        getline(cin, mensagem);
        cout << "Mensagem '" << mensagem <<"' Adicionada" << endl;
    } else {
        cout << "Mensagem '"<< argv[2] <<"' Adicionada" << endl;
    }
    
    return 0;
}

void show_usage(const string &prog_name)
{
    cout << "Uso: " << prog_name << " add <message>" << endl;

}

