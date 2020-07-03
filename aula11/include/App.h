#ifndef APP_H
#define APP_H

#include "Diary.h"


struct App{

    Diary diary;
    App(const string& filename);
    int run(int argc, const char* argv[]);
    int show_usage(const string &prog_name);
    void add();
    void add(const string message);
    void list();
    void search(string message);


};



#endif