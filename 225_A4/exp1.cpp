/*
Author: Mike Kim
Filename: exp1.cpp
Description: Experiment 1 of assignment 4.
Date (last modified): November 29th, 2022
*/



#include <iostream>
#include "time.h"

using namespace std;

double elapsed_time(clock_t start, clock_t finish)
{
	return (finish - start) / (double) (CLOCKS_PER_SEC/1000);
}
int main(void)
{
	const int arraySize = 1000000;
	
	int *a1 = new int [arraySize];
	int *a2 = new int [arraySize];
	
	//int temp; - not used bc calling it and unusing would still be sufficient
	clock_t first_start;
	clock_t first_finish;
	first_start = clock();
	for(int a =0; a < arraySize; a+=64) //cache hitting
	{	
		a1[a];
		a1[a+1];
		a1[a+2];
		a1[a+3];
		a1[a+4];
		a1[a+5];
		a1[a+6];
		a1[a+7];
		a1[a+8];
		a1[a+9];
		a1[a+10];
		a1[a+11];
		a1[a+12];
		a1[a+13];
		a1[a+14];
		a1[a+15];
		a1[a+16];	
	}
	first_finish = clock();
	double timer_1st = elapsed_time(first_start, first_finish);
	//double avg_1 = timer_1st ;
	cout << "Time taken for loop 1: " << timer_1st << endl; // took 0.06
	// ------------------------------------------------------
	//timer
	clock_t second_start;
	clock_t second_finish;
	
	second_start = clock();
	for(int b = 0; b < arraySize; b+=64) // cache missing 
	{
		a2[b];
	}
	second_finish = clock();
	
	double timer_2nd = elapsed_time(second_start, second_finish);
	
	cout << "Time taken for loop 2: " << timer_2nd << endl; // took 0.058
	
	return 0;
}
