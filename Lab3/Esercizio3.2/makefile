INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cpp funzioni.hpp
	g++ -o main main.cpp ${INCS} ${LIBS}

compila: main

esegui:
	./main data.dat

all: compila esegui

clean:
	rm *.log

cleanall:
	rm main
	rm *.log