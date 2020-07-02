#ifndef DATE_H
#define DATE_H

#include <string>

using namespace std;

struct Date {

  Date();
  unsigned dia;
  unsigned mes;
  unsigned ano;

  void setFromString(const string& date);
  string getCurrentDate();
  string formatCurrentDate(const string &format);

  string toString();
};



#endif