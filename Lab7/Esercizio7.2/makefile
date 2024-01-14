INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cpp funzioni.hpp integrale.hpp libreria.hpp
	g++ -o main main.cpp -std=c++11 ${INCS} ${LIBS}

esegui:
	./main 0.001

all: main esegui
