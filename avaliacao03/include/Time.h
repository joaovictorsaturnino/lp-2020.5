#ifndef TIME_H
#define TIME_F

#include <string>

using namespace std;

struct Time {

  Time();
  unsigned hora;
  unsigned minuto;
  unsigned segundo;

  void setFromString(const string& time); 
  string toString();
  string getCurrentTime();
  string formatCurrentDate(const string &format);

};
#endif