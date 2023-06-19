#include <iostream>
#include "BinarySearchTree.h"
#include "AvlTree.h"
#include "time.h"

using namespace std;

double elapsed_time( clock_t start, clock_t finish)
{
	return (finish - start) / (double) (CLOCKS_PER_SEC/1000);
}

int main(void)
{
	//create t1 and t2 for experiment part 1:
	BinarySearchTree<int> t1;
	BinarySearchTree<int> t2;
	////
	//t1
	clock_t start;
	clock_t finish;
	start = clock();
	int x =1;
	for(int i =0; i < 20000; i++)
	{
		t1.insert(x);
		x++;
	}
	finish = clock();
	int time_taken = elapsed_time(start,finish);
	cout << "Time taken (t1): " << time_taken << endl;
	
	// Sequence memebership check of t1:
	clock_t secondstart;
	clock_t secondfinish;
	secondstart = clock();
	for(int i=0; i < 20000; i++)
	{
		t1.contains(i);
	}
	secondfinish = clock();
	int time_taken2 = elapsed_time(secondstart, secondfinish);
	
	cout << "Average time for membership test (t1): " << time_taken2 << endl;
	
	
	//avg depth of search for membership test
	int a =0;
	for(int i=0; i < 20000 ; i++)
	{
		a += t1.depth(i); // stores all depth
	}
	
	//avg
	a = a / 20000; 
	cout << "The average depth of search for membership test (t1): " << a << endl;
	//Average depth of search for membership tests:
	
	
	////
	
	//t2
	const int gap = 1;
	const int cap = 20000;
	int node = cap/2;
	
	clock_t thirdstart;
	clock_t thirdfinish;
	thirdstart = clock();
	
	for (int o =0; o < 20000; o++)
	{
		node = (node + gap) % cap;
		t2.insert(node);
	}
	
	thirdfinish = clock();
	int time_taken3 = elapsed_time(thirdstart, thirdfinish);
	cout << "Time taken (t2): " << time_taken3 << endl;
	
	// Sequence memebership check of t2:
	clock_t fourthstart;
	clock_t fourthfinish;
	fourthstart = clock();
	for(int i=0; i < 20000; i++)
	{
		t1.contains(i);
	}
	fourthfinish = clock();
	int time_taken4 = elapsed_time(fourthstart, fourthfinish);
	
	cout << "Average time for membership test (t2): " << time_taken4 << endl;
	
	//Average depth of search for membership tests:
	int b = 0;
	for(int i =0; i < 20000; i++)
	{
		b += t2.depth(i);
		
	}
	
	b = b/20000;
	cout << "The average depth of search for membership test (t2): " << b << endl;
	

	return 0;
}


