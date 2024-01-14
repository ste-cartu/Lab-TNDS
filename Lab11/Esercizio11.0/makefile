INCS := `root-config --cflags`
LIBS := `root-config --libs`

main: main.cpp random.hpp prisma.hpp libreria.hpp
	g++ -o main main.cpp -std=c++11 ${INCS} ${LIBS}

esegui:
	./main 10000
clean:
	rm *.o

all: main esegui
