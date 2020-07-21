GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = supermercado

supermercado: Cliente.o Main.o Produto.o Estabelecimento.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) Cliente.o Main.o Produto.o Estabelecimento.o

Main.o: src/Main.cpp
	$(GCC) $(GCC_FLAGS) -c src/Main.cpp

Cliente.o: src/Cliente.cpp
	$(GCC) $(GCC_FLAGS) -c src/Cliente.cpp

Produto.o: src/Produto.cpp
	$(GCC) $(GCC_FLAGS) -c src/Produto.cpp	

Estabelecimento.o: src/Estabelecimento.cpp
	$(GCC) $(GCC_FLAGS) -c src/Estabelecimento.cpp	

clean:
	rm -f *.o supermercado	