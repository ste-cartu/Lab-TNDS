main: main.o posizione.o
	g++ -o main main.o posizione.o
	rm *.o

main.o: main.cpp posizione.hpp
	g++ -c -o main.o main.cpp

posizione.o: posizione.cpp posizione.hpp
	g++ -c -o posizione.o posizione.cpp
	


compila: main


clean:
	rm *.o

cleanall:
	rm main
	rm *.o
	rm *.log