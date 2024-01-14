main: main.o vettore.o
	g++ -o main main.o vettore.o

main.o: main.cpp vettore.h
	g++ -c main.cpp

vettore.o: vettore.cpp vettore.h
	g++ -c vettore.cpp

compila: main

esegui:
	./main

clean:
	rm *.o
