#include "../include/App.h"

#include <iostream>
#include <string>
#include <fstream>

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
        list_messages();
    } else if (acao == "search") {
        search(argv[2]);
    } else {
        return show_usage(argv[0]);
    }

    return 0;
}

void App::add(){
    string message;
    cout << "Digite a mensagem:" << endl;
    getline(cin, message);

    add(message);
}

void App::add(const string message)
{
    diary.add(message);
    diary.write();
}

void App::search(string message){
    vector<Message> messages = diary.search(message);
    
    if(messages.empty()){
        cout << "Desculpe, palavra não encontrada." << endl;
    } else {
        for(int i = 0; i < messages.size(); i++){
            cout << "Econtrada: - " << messages[i].content << endl;
        }
    }

}

void App::list_messages()
{

    for (size_t i = 0; i < diary.messages.size(); ++i) {
        cout << "- " << diary.messages[i].content << endl;
    }
}

int App::show_usage(const string &prog_name)
{
    cout << "Uso: "<< prog_name <<" 'add <message>' or 'list' or 'search <message>'" << endl;
    return 1;
}