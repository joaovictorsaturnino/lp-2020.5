#include "../include/Diary.h"

#include <iostream>
Diary::Diary(const string& filename) : messages_capacity(10),
    messages(nullptr), messages_size(0)
{
    messages_size = 0;
    messages = new Message[messages_capacity];
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
    cout << "Mensagem Adicionada." << endl;
    messages_size++;

}

void Diary::write(){
    //Aqui vai o método para gravar a mensagem
}