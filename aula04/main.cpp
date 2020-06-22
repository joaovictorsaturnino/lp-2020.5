#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void show_usage(const string &prog_name);

std::string format_current_date(const std::string &format) {
  std::time_t time = std::time(nullptr);
  char result[1024];

  std::strftime(result, sizeof(result), format.c_str(), std::localtime(&time));

  return std::string(result);
}

std::string get_current_date() { 
    return format_current_date("%d/%m/%Y"); 
}

std::string get_current_time() { 
    return format_current_date("%H:%M:%S"); 
}

int main(int argc, char const *argv[]){
    //string para armazenar a mensagem a ser adicionada    
    string mensagem;

    if (argc == 1){
        show_usage(argv[0]);
        
        return -1;
    }

    //string que contem a ação 'list' ou 'add'
    string action = argv[1];

    if (action != "add" && action != "list"){
        show_usage(argv[0]);
        return -1;
    }
    //streams de entrada e saida
    ofstream arquivo_saida{"teste.txt", ios::app};
    ifstream arquivo_entrada{"teste.txt"};

    //ação de listar as mensagens
    if (action == "list"){

        while (!arquivo_entrada.eof()){
            getline(arquivo_entrada, mensagem);

            if (mensagem.size() == 0){
                continue;
            }

            cout << mensagem << endl;
        }
    }


    //ação de adicionar as mensagens
    if (action == "add"){
        
        cout << "Escreva uma mensagem: " << endl;
        cin >> mensagem;
        arquivo_saida << "- " << get_current_time() << mensagem << endl;

        cout << "Mensagem Adicionada" << endl;
    }

    return 0;
}

void show_usage(const string &prog_name){
    cout << "Uso: " << prog_name << " 'add <message>' or 'list'" << endl;
}
