main: main.o funzioni.o
	g++ -o main main.o funzioni.o

main.o: main.cpp funzioni.h
	g++ -c main.cpp

funzioni.o: funzioni.cpp funzioni.h
	g++ -c funzioni.cpp

compila: main

esegui:
	./main 100000 data.dat

all: compila esegui

clean:
	rm *.o
