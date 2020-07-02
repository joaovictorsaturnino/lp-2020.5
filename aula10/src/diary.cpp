#include "../include/Diary.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
Diary::Diary(const string& filename) : filename(filename), messages_capacity(10),
    messages(nullptr), messages_size(0)
{   

    messages = new Message[messages_capacity];
    ifstream arquivo_leitura(filename);
    string linha;
    string dt;
    string hr;
    string type;
    string msg;
    
    Date d;
    Time t;

    int count;

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
            messages[count].content = msg;
            messages[count].date = d;
            messages[count].time = t;
            messages[count].messageExists = true;

            ++count;
            ++messages_size;
        }
        
        else {
            
        }    
        
    } 
}

Diary::~Diary(){
    delete[] messages;
}

void Diary::add(const string& message){
    cout << "entrei" << endl;
    if(messages_size == messages_capacity){
        messages_capacity *=2;
        Message* bigger_messages = new Message[messages_capacity];

        for(int i = 0; i < messages_size; i++){
            bigger_messages[i] = messages[i];
        }
    
        messages = bigger_messages;
    }
    
    Date d;
    d.setFromString(d.getCurrentDate());
    Time t;
    t.setFromString(t.getCurrentTime());
    Message m;
    m.messageExists = false;
    m.content = message;
    m.date = d;
    m.time = t;
    messages[messages_size] = m;

    messages_size++;

}

void Diary::write(){

    ofstream arquivo_saida{filename, ios::app};
    ifstream arquivo_entrada{filename};

    for(int i = 0; i < messages_size; i++){

        if(messages[i].messageExists == true){
            // continue;
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
            cout << messages_size << endl;
            cout << messages_capacity << endl;
            
        }
    }
    arquivo_entrada.close();
    arquivo_saida.close();

}

Message* Diary::search(string message){

    for(int i = 0; i < messages_size; ++i){
        int founded_Message = messages[i].content.find(message);

        if(founded_Message < messages[i].content.npos) {
            return &messages[i];
        }
    }
    return nullptr;
}
