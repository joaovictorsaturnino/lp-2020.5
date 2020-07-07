#include "../include/App.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

string config_inicial();

int main(int argc, char const *argv[]){
    
    string filename = config_inicial();

    App app(filename);

    return app.run(argc, argv);
}

//função para criar o arquivo de configuração padrão ou para ler o caminho do arquivo
string config_inicial(){
    string filename;
    ifstream arquivo_config("diary.config");

    //caso não exista arquivo de configuração, o programa cria um com os padrões estabelecidos, 
    if(arquivo_config.fail()){
        ofstream arquivo("diary.config", ios::app);
        arquivo << "path = diary.md" << endl;
        arquivo << "default_format = %d %t: %m"<< endl; 
        filename = "diary.md";
    }
    /*caso exista, o programa percorre a linha para achar a linha 'path' e dar nome para o arquivo que vai ser criado
      para armazenar as mensagens */
    else{
        while(!arquivo_config.eof()){
            string linha;
            string config;
            string discard_path;
            
            getline(arquivo_config,linha);
            stringstream stream(linha);
            stream >> config;

            if(config.compare("path") == 0){
                stream >> discard_path;
                stream >> filename;

            }
        }
    }
    //retrorna o caminho para o arquivo com o nome dele no fim
   return filename; 

}