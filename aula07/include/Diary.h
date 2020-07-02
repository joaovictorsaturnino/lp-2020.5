#ifndef DIARIO_H
#define DIARIO_H

#include <string>
#include <fstream>
#include "Message.h"

using namespace std;

struct Diary{

    Diary(const string& filename);
    
    ~Diary();
    Message* messages;
    string filename;
    //streams de entrada e saida
    ofstream arquivo_saida{filename, ios::app};
    ifstream arquivo_entrada{filename};
    size_t messages_size;
    size_t messages_capacity;

    void add(const string& message);
    void write();


};

#endif