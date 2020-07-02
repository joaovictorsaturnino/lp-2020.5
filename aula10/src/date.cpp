#include "../include/Date.h"
#include <sstream>
#include <ctime>

using namespace std;
Date::Date() : ano(0), mes(0), dia(0){

}

void Date::setFromString(const string &date){
    
    stringstream stream_d(date);
    char discard_d;

    stream_d >> dia;
    stream_d >> discard_d;
    stream_d >> mes;
    stream_d >> discard_d;
    stream_d >> ano;

}

string Date::formatCurrentDate(const string &format) {
    std::time_t time = std::time(nullptr);
    char result[1024];

    strftime(result, sizeof(result), format.c_str(), localtime(&time));

    return string(result);
}

string Date::getCurrentDate() 
{
    return formatCurrentDate("%d/%m/%Y");
}

string Date::toString(){

    stringstream stream;

    if (dia < 10) {
        stream << 0;
    }
    stream << dia;
    stream << '/';

    if (mes < 10) {
        stream << "0";
    }
    stream << mes << "/";
    stream << ano;

    return stream.str();
}

