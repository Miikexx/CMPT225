/*
*
* Filename: DQArraytest.cpp
*
* Date (Last modified): Sept 29th, 2022
*
* Name: Mike Kim
*
* Description: This is the test program that will demonstrate the correctness of an
*              implementation of the array.
*/

#include <iostream>
#include "deque.h"

using namespace std;

int main(void)
{
	Deque<int> D;
	
	for(int i =0; i < 6; i++)
	{
		D.enqueue(i*2); // 0,2,4,6,8,10
	}
	
	cout << "D[1] = " << D[1] << endl;
	cout << "D[3] = " << D[3] << endl;
	cout << "D[5] = " << D[5] << endl;
	
	
	return 0;
	
}
