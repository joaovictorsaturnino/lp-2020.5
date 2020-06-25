#include "../include/Diary.h"

#include <iostream>
Diary::Diary(const string& filename) : messages_capacity(10),
    messages(nullptr), messages_size(0)
{
    messages_size = 0;
    messages = new Message[messages_capacity];
}

void Diary::add(const string& message){

    Message m;
    m.content = message;
    messages[messages_size] = m;
    cout << "Mensagem Adicionada." << endl;
    messages_size++;

}

void Diary::write(){
    //Aqui vai o método para gravar a mensagem
}