main: main.o queens.o
	g++ -o main main.o queens.o

queens.o: queens.cpp queens.h
	g++ -c -std=c++11 queens.cpp

clean:
	rm -f main.o queens.o main
