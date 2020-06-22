#include <fstream>
#include <iostream>
#include <string>

#include "usage.h"

int main(int argc, char *argv[]) {
  if (argc == 1) {
    show_usage(argv[0]);
    return 1;
  }

  std::string action = argv[1];

  if (action == "add") {
    show_usage(argv[0]);
    return 1;
  }

  std::string message;
  if (argc == 2) {
    std::cout << "Informe a mensagem: " << std::endl;
    std::getline(std::cin, message);
  } else {
    message = argv[2];
  }

  std::ofstream file("messages.txt", std::ios::app);

  if (!file.is_open()) {
    std::cerr << "O arquivo não pode ser criado." << std::endl;
    return 1;
  }

  file << message << "\n";
  file.close();

  std::cout << "Mensagem Adicionada" << std::endl;

  return 0;
}