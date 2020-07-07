GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = diary

diary: app.o date.o time.o diary.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) app.o date.o time.o diary.o main.o

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

diary.o: src/diary.cpp
	$(GCC) $(GCC_FLAGS) -c src/diary.cpp

date.o: src/date.cpp
	$(GCC) $(GCC_FLAGS) -c src/date.cpp

time.o: src/time.cpp
	$(GCC) $(GCC_FLAGS) -c src/time.cpp

app.o: src/app.cpp
	$(GCC) $(GCC_FLAGS) -c src/app.cpp

clean:
	rm -f *.o diary	