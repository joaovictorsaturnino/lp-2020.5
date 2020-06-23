#ifndef DIARIO_H
#define DIARIO_H

#include <string>
#include "Message.h"

using namespace std;

struct Diary{

    Diary(const std::string& filename);
    
    Message* messages;
    string filename;
    size_t messages_size;
    size_t messages_capacity;

    void add(const string& message);
    void write();



};

#endif