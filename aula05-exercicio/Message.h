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

  bool comparar_datas(const Message &other_message);
};

#endif