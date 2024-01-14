main: main.o vettore.o funzioni.o
	g++ -o main main.o vettore.o funzioni.o

main.o: main.cpp funzioni.h
	g++ -c -o main.o main.cpp

funzioni.o: funzioni.cpp funzioni.h
	g++ -c -o funzioni.o funzioni.cpp

vettore.o: vettore.cpp vettore.h
	g++ -c -o vettore.o vettore.cpp


compila: main

esegui:
	./main 100000 data.dat > log.log 2> err.log

all: compila esegui

clean:
	rm *.o
	rm *.log

cleanall:
	rm main
	rm *.o
	rm *.log