#include <iostream>
/*
desenvolvido por João victor
ps.: comentários em // mostram como o código ficaria caso fosse inserido
o "using namespace std"
*/
//using namespace std
int main(int argc, char *argv[]) {
  int a = 10;
  int b = 50;

  int n1 = 0;
  int n2 = 0;
  //cout
  std::cout << "Informe o primeiro número: ";
  //cin
  std::cin >> n1;
  //cout
  std::cout << "Informe o segundo número: ";
  //cin
  std::cin >> n2;

  int sum = n1 + n2;
  //cout
  std::cout << "A soma dos números é " << sum << std::endl;
  return 0;
}