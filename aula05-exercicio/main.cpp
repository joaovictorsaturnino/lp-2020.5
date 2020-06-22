#include "Message.h"
#include "usage.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Message m1;

  m1.date.dia = 22;
  m1.time.hora = 8;
  m1.content = "Olá, Mundo";

  Message m2;
  m2.date.dia = 22;
  m2.time.hora = 8;
  m2.content = "Hello, World";

  m1.comparar_datas(m2);
}