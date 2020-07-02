#include "../include/Diary.h"

#include <iostream>
#include <fstream>
using namespace std;
Diary::Diary(const string& filename) : messages_capacity(10),
    messages(nullptr), messages_size(0)
{
    messages = new Message[messages_capacity];
    //streams de entrada e saida
    ofstream arquivo_saida{filename, ios::app};
    ifstream arquivo_entrada{filename};

}

Diary::~Diary()
{
    delete[] messages;
}
void Diary::add(const string& message){
    
    
    if (messages_size == messages_capacity) {
        return;
    }

    Date d;
    d.setFromString(d.getCurrentDate());
    Time t;
    t.setFromString(t.getCurrentTime());

    Message m;
    m.content = message;
    m.date = d;
    m.time = t;
    messages[messages_size] = m;


    // arquivo_saida << "ola" << endl;
    // arquivo_saida << "# " << m.date.dia << "/";
    // arquivo_saida << m.date.mes << "/";
    // arquivo_saida << m.date.ano << endl;
    // arquivo_saida << m.time.hora << ":";
    // arquivo_saida << m.time.minuto << ":";
    // arquivo_saida << m.time.segundo << " ";
    // arquivo_saida << m.content;
    cout << m.content << endl;
    
    cout << "Mensagem Adicionada." << messages_size << endl;
    messages_size++;
    

}

void Diary::write(){

    cout << "entrei" << endl;
    

    arquivo_saida << messages[0].date.ano << endl;
}