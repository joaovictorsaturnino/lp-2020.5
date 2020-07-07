#include "../include/App.h"

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

App::App(const string& filename) : diary(filename){

}

int App::run(int argc, char const * argv[]){

    if (argc == 1) {
        return show_usage(argv[0]);
    }

    string acao = argv[1];

    if (acao == "add") {
        if (argc == 2) {
            add();
        } else {
            add(argv[2]);
        }
    } else if (acao == "list") {
        list();
    } else if (acao == "search") {
        search(argv[2]);
    } else if(acao == "interactive"){
        //Uso interativo do programa
        int opc = 15;
        while(opc != 0){
            cout << endl << endl << "Diário 1.0" << endl << endl;
            cout << "Selecione uma ação: " << endl;
            cout << "1) Listar mensagens"<< endl;
            cout << "2) Adicionar nova mensagem"<< endl;
            cout << endl;
            cout << "0) Finalizar" << endl << endl;
            cout << "opção: ";
            cin >> opc;

            if(opc == 1){
                list();
            }
            
            if(opc == 2){
                string message;
                cout << "Digite a mensagem:" << endl;
                getline(cin.ignore(), message);
                add(message);
                opc++;
            }
            if(opc == 0){
                break;
            }if(opc != 0 && opc != 1 && opc !=2){
                cout << "Opção inválida. Tente novamente!" << endl;
            }

        }

    } else {
        return show_usage(argv[0]);
    }

    return 0;
}
//Listagem seguindo o formato do arquivo de cofiguração (não consegui inserir espaços, caso hajam)
void App::list(){
    ifstream arquivo_config ("diary.config");
    string format;
    string linha;
    while(!arquivo_config.eof()){
        
        string config;
        string discard_df;
        
        getline(arquivo_config,linha);
        stringstream stream(linha);
        stream >> config;

        //salvando o formato da msg na string
        if(config.compare("default_format") == 0){
            stream >> discard_df;
            stream >> format;

        }
    }
    cout << "listando mensagens: " << endl;

    for (int i = 0; i < diary.messages.size()-1; i++){
        
        stringstream output (format);
        //array de char do tamanho da string que contem o formato
        char f [format.size()];

        //preenchimento de cada posição do vetor com um caracter da string formato
        for(int j = 0; j < format.size(); j++){
            output >> f[j];
        }
        //percorrendo o array de char para comparar os caracteres
        for(int k = 0; k < format.size(); k++){
            if(f[k] == '%'){
                if(f[k+1] == 'd'){
                    cout << " " << diary.messages[i].date.toString();
                    
                }
                if(f[k+1] == 't'){
                    cout << " " << diary.messages[i].time.toString();
                    
                }
                if(f[k+1] == 'm'){
                    cout << " " << diary.messages[i].content;
                    
                }

            }else{
                if(f[k]!= 'd' && f[k]!= 't' && f[k]!= 'm'){
                    cout << " " << f[k];
                }   
            }
        }
    cout << endl;
    }
}

void App::add(){
    string message;
    cout << "Digite a mensagem:" << endl;
    getline(cin, message);
    add(message);
}

void App::add(const string message){
    diary.add(message);
    diary.write();
}

void App::search(string message){
    vector<Message> messages = diary.search(message);
    
    if(messages.empty()){
        cout << "Desculpe, palavra não encontrada." << endl;
    } else {
        for(int i = 0; i < messages.size()-1; i++){
            cout << "Encontrada:"<< messages[i].date.toString() <<" - " << messages[i].time.toString() << " " << messages[i].content << endl;
        }
    }

}

int App::show_usage(const string &prog_name)
{
    cout << "Uso: "<< prog_name <<" 'add <message>' or 'list' or 'search <message>'" << endl;
    return 1;
}