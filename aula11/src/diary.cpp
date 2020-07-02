#include "../include/Diary.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
Diary::Diary(const string& filename) : 
    filename(filename)
{   

    ifstream arquivo_leitura(filename);
    string linha;
    string dt;
    string hr;
    string type;
    string msg;
    Message old_messages;
    Date d;
    Time t;

    while(!arquivo_leitura.eof()){
        
        getline(arquivo_leitura,linha);
        stringstream stream(linha);
        stream >> type;
        if(type.compare("#") == 0){
            stream >> dt;
        }

        if (type.compare("-") == 0) {
            stream >> hr;
            stream >> msg;
            d.setFromString(dt);
            t.setFromString(hr);
            old_messages.content = msg;
            old_messages.date = d;
            old_messages.time = t;
            old_messages.messageExists = true;

            messages.push_back(old_messages);
        }
        
        else {
            
        }    
        
    } 
}


void Diary::add(const string& message){
    
    Date d;
    d.setFromString(d.getCurrentDate());
    Time t;
    t.setFromString(t.getCurrentTime());
    Message current_Message;
    current_Message.messageExists = false;
    current_Message.content = message;
    current_Message.date = d;
    current_Message.time = t;

    messages.push_back(current_Message);
}

void Diary::write(){

    ofstream arquivo_saida{filename, ios::app};
    ifstream arquivo_entrada{filename};

    for(int i = 0; i < messages.size(); i++){

        if(messages[i].messageExists == true){
            continue;
        }else{
            
            int achouData = 0;
            string linha = "";
            string data = "# " + messages[i].date.toString();

            while (!arquivo_entrada.eof()){
                getline(arquivo_entrada, linha);
                /*Verificando se a data atual está presente na linha que está sendo lida no momento, se sim ocorre o brake.
                Caso não haja, o programa escreve na linha a data atual.*/
                if(linha.find(data) != string::npos && linha != ""){
                    achouData = 1;
                    break;
                }else{
                        
                }       
            }

                //se tem a data, só adiciona a mensagem, se não, adiciona data e mensagem
                if(achouData){
                    arquivo_saida << "- " << messages[i].time.toString() << " ";
                    arquivo_saida << messages[i].content << endl;
                }else{
                    arquivo_saida << endl << "# " << messages[i].date.toString() << endl;
                    arquivo_saida << "- "<< messages[i].time.toString() << " ";
                    arquivo_saida << messages[i].content << endl;
                }

            cout << "Mensagem Adicionada" << endl;
            
        }
    }
    arquivo_entrada.close();
    arquivo_saida.close();

}

vector<Message> Diary::search(string message){
    vector<Message> searched_messages;
    for(int i = 0; i < messages.size(); ++i){
        int founded_Message = messages[i].content.find(message);

        if(founded_Message < messages[i].content.npos) {
            Message founded;
            founded.content = messages[i].content;
            searched_messages.push_back(founded);
        }
    }
    return searched_messages;
}
