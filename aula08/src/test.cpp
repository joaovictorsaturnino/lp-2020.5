#include "../include/Date.h"
#include "../include/Time.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
int main(int argc, char const *argv[])
{
    string date = "25/06/2020";
    Date d;
    Time t;

    stringstream stream_d(date);
    char discard_d;

    stream_d >> d.dia;
    stream_d >> discard_d;
    stream_d >> d.mes;
    stream_d >> discard_d;
    stream_d >> d.ano;

    cout << d.dia << endl;
    cout << d.mes << endl;
    cout << d.ano << endl;

    string time = "11:37:09";
    stringstream stream_t(time);
    char discard_t;
    
    stream_t >> t.hora;
    stream_t >> discard_t;
    stream_t >> t.minuto;
    stream_t >> discard_t;
    stream_t >> t.segundo;

    cout << t.hora << endl;
    cout << t.minuto << endl;
    cout << t.segundo << endl;


    return 0;
}
