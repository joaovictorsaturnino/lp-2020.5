#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

struct Date {
  unsigned dia;
  unsigned mes;
  unsigned ano;

  void setFromString(const string& date);
};



#endif