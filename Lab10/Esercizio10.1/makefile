INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cpp random.hpp libreria.hpp
	g++ -o main main.cpp -std=c++11 ${INCS} ${LIBS}

esegui:
	./main 1000000 10 2> err.log

clean:
	rm *.log

all: main esegui
