all: DQtest DQarraytest

DQtest: DQtest.o
	g++ -Wall -o DQtest DQtest.o
	
DQarraytest: DQarraytest.o
	g++ -Wall -o DQarraytest DQarraytest.o
	
Dqtest.o: DQtest.cpp deque.h
	g++ -Wall -o DQtest.o -c DQtest.cpp
	
Dqarraytest.o: DQtest.cpp deque.h
	g++ -Wall -o DQarraytest.o -c DQarraytest.cpp

clean:
	rm -f DQtest DQarraytest *.o
