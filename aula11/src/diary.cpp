#include "../include/Diary.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
Diary::Diary(const string& filename) : filename(filename) {   

    ifstream arquivo_leitura(filename);

    if (arquivo_leitura.fail()){
       
    }else{

        Message old_messages;
        Date d;
        Time t;
        string linha;
        string date_stream;
        string time_stream;
        string character;
        string content;

        while(!arquivo_leitura.eof()){
            
            getline(arquivo_leitura,linha);
            stringstream stream(linha);
            stream >> character;

            if(character.compare("#") == 0){
                stream >> date_stream;
            }

            if (character.compare("-") == 0) {
                stream >> time_stream;
                stream >> content;
                d.setFromString(date_stream);
                old_messages.date = d;
                t.setFromString(time_stream);
                old_messages.time = t;
                old_messages.content = content;
                
                old_messages.messageExists = true;
                messages.push_back(old_messages);
            }   
        }
    } 
}


void Diary::add(const string& message){
    Message current_Message;
    
    Date d;
    d.setFromString(d.getCurrentDate());
    current_Message.date = d;
    Time t;
    t.setFromString(t.getCurrentTime());
    current_Message.time = t;
    current_Message.content = message;

    current_Message.messageExists = false;
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

            //se tem a data, só adiciona a mensagem (com horário), se não, adiciona data e mensagem (com horário)
            if(achouData){
                arquivo_saida << "- " << messages[i].time.toString() << " ";
                arquivo_saida << messages[i].content << endl;
            }
            if(!achouData){
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
    Message founded;
    
    for(int i = 0; i < messages.size(); i++){
        string cmp = messages[i].content;
        c << endl;
        if(cmp.compare(message) == 0) {
            founded.content = messages[i].content;
            founded.time = messages[i].time;
            searched_messages.push_back(founded);
        }
    }
    cout << searched_messages.size() << endl;
    return searched_messages;
}
