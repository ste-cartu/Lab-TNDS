INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cpp parabola.hpp funzione.hpp bisezione.hpp solutore.hpp
	g++ -o main main.cpp -std=c++11 ${INCS} ${LIBS}

esegui:
	./main

cleanall:
	rm main
