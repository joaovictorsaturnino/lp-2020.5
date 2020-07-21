GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = banco

banco: Conta.o Main.o Cliente.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) Conta.o Main.o Cliente.o

Conta.o: src/Conta.cpp
	$(GCC) $(GCC_FLAGS) -c src/Conta.cpp

Main.o: src/Main.cpp
	$(GCC) $(GCC_FLAGS) -c src/Main.cpp

Main.o: src/Cliente.cpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

clean:
	rm -f *.o banco	