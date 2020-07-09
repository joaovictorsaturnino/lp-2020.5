GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = carro

carro: Carro.o Main.o Motor.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) Carro.o Main.o Motor.o


Carro.o: src/Carro.cpp
	$(GCC) $(GCC_FLAGS) -c src/Carro.cpp

Main.o: src/Main.cpp
	$(GCC) $(GCC_FLAGS) -c src/Main.cpp

Motor.o: src/Motor.cpp
	$(GCC) $(GCC_FLAGS) -c src/Motor.cpp	

clean:
	rm -f *.o banco	