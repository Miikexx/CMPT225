/*
Author: Mike Kim
Filename: exp3.cpp
Description: Experiment 1 of assignment 4.
Date (last modified): December 6th, 2022
*/
#include <iostream>
#include "time.h"

#include "list.h"
#include "ull.h"


using namespace std;

double elapsed_time(clock_t start, clock_t finish)
{
	return (finish - start) / (double) (CLOCKS_PER_SEC/1000);
}

int main(void)
{
	double t1 = 0;
	double t2 = 0;
	double t3 = 0;
	
	// ---------------------timer setup for 3 cases:
	clock_t first_start; // first_start = clock();
	clock_t first_finish; // first_finish = clock();
	
	
	clock_t second_start;
	clock_t second_finish;
	
	clock_t third_start;
	clock_t third_finish;
	// -----------------------------------------------
	// array setup
	const int mill = 1000000;
	int *arr = new int [mill];
	// assign values to array
	for (int i =0; i < mill; i++)
	{
		arr[i] = i;
	}
	
	// linked list setup;
	
	List<int> linkedlist;
	for (int i =0; i < mill; i++)
	{
		linkedlist.push_back(i);
	}

	// ULL setup:
	
	ULListStr ull;
	
	for(int i=0; i < mill; i++)
	{
		ull.push_front(i);
	}
	
	// -- End of setup --------------------------
	// Traversal 1: ------------------------------------
	first_start = clock();
	for(int i=0; i < mill; i++)
	{
		arr[i];
	}
	first_finish = clock();
	double timer_1 = elapsed_time(first_start, first_finish);
	t1 = timer_1;
	// ---------------------------------------------------
	
	// Traversal 2: ------------------------------------
	second_start = clock();
	linkedlist.traverse();
	
	second_finish = clock();
	double timer_2 = elapsed_time(second_start, second_finish);
	t2 = timer_2;
	// ------------------------------------------------------
	
	// Traversal 3: ------------------------------------
	third_start = clock();
	ull.traverse();
	third_finish = clock();
	double timer_3 = elapsed_time(third_start, third_finish);
	t3 = timer_3;
	
	// ---- Final result
	cout << "Time consumed to traverse a list implemented in array: " << t1 << endl;
	cout << "Time consumed to traverse a list implemented in linked list: " << t2 << endl;
	cout << "Time consumed to traverse a list implemented in unrolled linked list: " << t3 << endl;
	
	return 0;
}
