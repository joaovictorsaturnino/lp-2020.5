#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[]) {
  ifstream file;

  file.open("teste.txt");

  if (!file.is_open()) {
    cerr << "Arquivo não existente ou sem permissão de leitura."
              << endl;
    return 1;
  }

  string message;

  int line_number = 0;

  while (!file.eof()) {
    ++line_number;
    getline(file, message);

    if (message.size() == 0) {
      continue;
    }

    cout << line_number << ". " << message << endl;
  }

  file.close();

  return 0;
}