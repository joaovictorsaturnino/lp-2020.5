#include "../include/Diary.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
Diary::Diary(const string& filename) : filename(filename), messages_capacity(10),
    messages(nullptr), messages_size(0)
{   

    messages = new Message[messages_capacity];
    
}

Diary::~Diary()
{
    delete[] messages;
}
void Diary::add(const string& message){
    
    
    Date d;
    d.setFromString(d.getCurrentDate());
    Time t;
    t.setFromString(t.getCurrentTime());
    Message m;
    m.content = message;
    m.date = d;
    m.time = t;
    messages[messages_size] = m;

    messages_size++;

}

void Diary::write(){
    //streams de entrada e saida
    ofstream arquivo_saida{filename, ios::app};
    ifstream arquivo_entrada{filename};
    int achouData = 0;
    string linha = "";
    string data = "# " + messages[0].date.toString();

    string data_str = messages[0].date.toString();
    string time_str = messages[0].time.toString();

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
            arquivo_saida << "- " << time_str << " ";
            arquivo_saida << messages[0].content << endl;
        }else{
            arquivo_saida << endl << "# " << data_str << endl;
            arquivo_saida << "- "<< time_str << " ";
            arquivo_saida << messages[0].content << endl;
        }

    cout << "Mensagem Adicionada" << endl;
    
    arquivo_entrada.close();
    arquivo_saida.close();
}