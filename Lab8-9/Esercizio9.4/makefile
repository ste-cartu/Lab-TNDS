INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cpp libreria.hpp equ.diff.hpp
	g++ -o main main.cpp -std=c++11 ${INCS} ${LIBS}

esegui:
	./main 0.01 5 100 2> err.log

clean:
	rm *.log

all: main esegui
