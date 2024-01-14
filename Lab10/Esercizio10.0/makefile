INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cpp random.hpp funzioni.hpp
	g++ -o main main.cpp -std=c++11 ${INCS} ${LIBS}

esegui:
	./main 1 2> err.log

clean:
	rm *.log

all: main esegui
