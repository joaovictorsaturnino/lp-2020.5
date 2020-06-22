/*
* Aluno: João Victor da Silva Saturnino
* Matrícula: 20190035916
*/
#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

void show_usage(const string &prog_name);

//Código para receber a hora e data atuais
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
//Fim

int main(int argc, char const *argv[]){
    
    //string para armazenar a mensagem a ser adicionada    
    string mensagem;

    //String que contem a ação 'list' ou 'add'
    string action = argv[1];

    //Casos em que se deve mostrar o uso correto do programa
    if (argc == 1){
        show_usage(argv[0]);
        
        return -1;
    }
    if (action != "add" && action != "list"){
        show_usage(argv[0]);
        return -1;
    }

    //Streams de entrada e saida
    ofstream arquivo_saida{"teste.txt", ios::app};
    ifstream arquivo_entrada{"teste.txt"};

    if (!arquivo_entrada.is_open()) {   
        cerr << "Arquivo não existente ou sem permissão de leitura."<< endl;
        return 1;
    }

    //Sção de listar as mensagens
    if (action == "list"){
        //Verificação de existência do arquivo ou de permissão para acessá-lo
        if(arquivo_entrada.fail()){
            cout << "O arquivo de onde você pretende listar as mensagens não existe ou não há permissão para lê-lo" << endl;
        }

        //Percorrendo as linhas do arquivo
        while (!arquivo_entrada.eof()){
            string cmp = "-";
            getline(arquivo_entrada, mensagem);

            //verificando se nas linhas do arq. existe o caracter "-", que indica que naquela ali há uma mensagem
            if(mensagem.find(cmp) != string::npos){
                cout << mensagem << endl;
            }

            if (mensagem.size() == 0){
                continue;
            }    
        }
    }

    //Ação de adicionar as mensagens
    if (action == "add"){
        cout << "Escreva uma mensagem: " << endl;
        cin >> mensagem;
        int achouData = 0;
        string data = "# " + get_current_date();
        string linha = "";
        
        //Percorrendo as linhas do arquivo
        while (!arquivo_entrada.eof()){
            
            getline(arquivo_entrada, linha);
  
            /*Verificando se a data atual está presente na linha que está sendo lida no momento, se sim ocorre o brake.
            Caso não haja, o programa escreve na linha a data atual.*/
            
            //se achar a data na linha, muda o achouData para 1
            if(linha.find(data) != string::npos && linha != ""){
                achouData = 1;
                break;                
            }else{
                
            }       
        }

        //se tem a data, só adiciona a mensagem, se não, adiciona data e mensagem
        if(achouData){
            arquivo_saida << "- " << get_current_time() << " " << mensagem << endl;
        }else{
            arquivo_saida << endl << data << endl;
            arquivo_saida << "- " << get_current_time() << " " << mensagem << endl;
        }
        
        cout << "Mensagem Adicionada" << endl;
    
    }
    arquivo_entrada.close();
    arquivo_saida.close();
    return 0;
}
//Função chamada para expicar o uso do programa
void show_usage(const string &prog_name){
    cout << "Uso: " << prog_name << " 'add <message>' or 'list'" << endl;
}
