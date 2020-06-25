#ifndef TIME_H
#define TIME_F

#include <string>

using namespace std;

struct Time {
  unsigned hora;
  unsigned minuto;
  unsigned segundo;

  void setFromString(const string& time); 
  string to_string();
};



#endif