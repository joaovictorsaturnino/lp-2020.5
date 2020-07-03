#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include "Time.h"
#include "Date.h"

using namespace std;

struct Message {
  Date date;
  Time time;
  string content;
  bool messageExists;

  
};
#endif