#ifndef DIARIO_H
#define DIARIO_H

#include <string>
#include <fstream>
#include <vector>
#include "Message.h"

using namespace std;

struct Diary{

    Diary(const string& filename);
    
    vector<Message> messages;
    string filename;
    void add(const string& message);
    void write();
    vector<Message> search(string message);

};
#endif