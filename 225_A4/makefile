all: exp1 exp3

exp1: exp1.o
	g++ -Wall -o exp1 exp1.o
	
exp3: exp3.o
	g++ -Wall -o exp3 exp3.o
	
exp1.o: exp1.cpp
	g++ -Wall -o exp1.o -c exp1.cpp

exp3.o: exp3.cpp list.h ull.h
	g++ -Wall -o exp3.o -c exp3.cpp
	
clean:
	rm -f exp1 exp3 *.o
