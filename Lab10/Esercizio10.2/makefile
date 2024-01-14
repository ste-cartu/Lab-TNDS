INCS := `root-config --cflags`
LIBS := `root-config --libs`

main1: calcoli.cpp random.hpp libreria.hpp integrale.MC.hpp
	g++ -o calcoli calcoli.cpp -std=c++11 

main2: grafici.cpp
	g++ -o grafici grafici.cpp ${INCS} ${LIBS}

compila1: main1

compila2: main2

esegui1:
	./calcoli 100 10000 5

esegui2:
	./grafici

clean:
	rm *.dat

conti: main1 esegui1

altro: main2 esegui2
