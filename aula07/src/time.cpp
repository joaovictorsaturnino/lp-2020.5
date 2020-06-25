#include "../include/Time.h"
#include <sstream>
#include <ctime>

using namespace std;

Time::Time(): hora(0), minuto(0), segundo(0){

}

void Time::setFromString(const string &time){
    
    stringstream stream_t(time);
    char discard_t;

    stream_t >> hora;
    stream_t >> discard_t;
    stream_t >> minuto;
    stream_t >> discard_t;
    stream_t >> segundo;
}

string Time::formatCurrentDate(const string &format) {
    std::time_t time = std::time(nullptr);
    char result[1024];

    strftime(result, sizeof(result), format.c_str(), localtime(&time));

    return string(result);
}

string Time::getCurrentTime() { 
    return formatCurrentDate("%H:%M:%S"); 
}