all: Exp1 Exp2 DLtest Htest Dtest

Exp1: Exp1.o
	g++ -Wall -o Exp1 Exp1.o

Exp2: Exp2.o
	g++ -Wall -o Exp2 Exp2.o

DLtest: DLtest.o
	g++ -Wall -o DLtest DLtest.o

Htest: Htest.o
	g++ -Wall -o Htest Htest.o
	
Dtest: Dtest.o
	g++ -Wall -o Dtest Dtest.o
	
Exp1.o: Exp1.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o Exp1.o -c Exp1.cpp

Exp2.o: Exp2.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o Exp2.o -c Exp2.cpp
	
DLtest.o: DLtest.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o DLtest.o -c DLtest.cpp

Htest.o: Htest.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o Htest.o -c Htest.cpp

Dtest.o: Dtest.cpp BinarySearchTree.h dsexceptions.h
	g++ -Wall -o Dtest.o -c Dtest.cpp
	
clean:
	rm -f Exp1 Exp2 DLtest Htest Dtest *.o
