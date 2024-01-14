main: main.cpp vettore.hpp funzioni.hpp
	g++ -o main main.cpp

compila: main

esegui:
	./main 100000 data.dat > log.log 2> err.log

all: compila esegui

clean:
	rm *.log

cleanall:
	rm main
	rm *.log

