/*
*
* Filename: DQtest.cpp
*
* Date (Last modified): Sept 29th, 2022
*
* Name: Mike Kim
*
* Description: This is the test program that will demonstrate the correctness of an
*              implementation of the deque class.
*/

#include "deque.h"
#include <iostream>
#include <string.h>
using namespace std;

int main (void)
{
	
	// Create a double ended queue with an int data type:
	Deque<int> intDeque;
	cout << "Dequeue with int data type: " << endl;
	cout << "Prior to any modifications:"<< endl;
	cout<< "display function:"<<endl;
	intDeque.display();
	cout <<"\n";
	cout<< "ddisplay function: "<<endl;
	intDeque.ddisplay();
	cout <<"\n";
	cout << "Enqueueing ten elements (1-10) then jumping '35', '36', and '37': " << endl;
	cout << "After enqueueing:" << endl;
	for(int i=1; i<11; i++)
	{
		intDeque.enqueue(i);
	}
	intDeque.display();
	cout <<"\n";
	intDeque.ddisplay();
	cout <<"\n";
		 
	intDeque.jump(35);
	intDeque.jump(36);
	intDeque.jump(37);
	cout << "After jumping: " << endl;
	intDeque.display();
	cout <<"\n";
	intDeque.ddisplay();
	cout <<"\n";
	cout << "Ejecting two elements:" << endl;
	intDeque.eject();
	intDeque.eject();
	intDeque.display();
	cout <<"\n";
	intDeque.ddisplay();
	cout <<"\n";
	cout << "Increasing the capacity to 20 by using reserve:" << endl;
	intDeque.reserve(20);
	intDeque.display();
	cout <<"\n";
	intDeque.ddisplay();
	cout <<"\n";
	cout<< "Using the clear function:" << endl;
	intDeque.clear();
	intDeque.display();
	cout <<"\n";
	intDeque.ddisplay();
	cout <<"\n";
	/////////////////////////////////////////////////////////////////////////
	
	cout << " ------------------------------------------------------" << endl;
	cout << "Deque with string data type:" << endl;
	//Section 2: Dequeue for string
	Deque<string> strDeque;
	
	//Section 2-1: Enqueueing + jumping
	cout << "Enqueueing three elements then jumping three times:" << endl;
	strDeque.enqueue("three");
	strDeque.enqueue("four");
	strDeque.enqueue("five");
	strDeque.jump("two");
	strDeque.jump("one");
	strDeque.display();
	cout <<"\n";
	strDeque.ddisplay();
	cout <<"\n";
	cout<< "Dequeueing 2 elements:" << endl;
	
	for(int i=0; i <2; i++)
	{
		strDeque.dequeue();
	}
	
	strDeque.display();
	cout <<"\n";
	strDeque.ddisplay();
	
	//Section 2-3 - Ejecting:
	cout <<"\n";
	cout <<"Ejecting two elements: " << endl;
	for(int i =0; i < 2; i++)
	{
		strDeque.eject();
	}
	strDeque.display();
	cout <<"\n";
	strDeque.ddisplay();
	
	//Section 2-4 - reserve:
	cout <<"\n";
	cout << "Increasing the capacity to 13 using reserve function: " << endl;
	strDeque.reserve(13);
	strDeque.display();
	cout <<"\n";
	strDeque.ddisplay();
	//Section 2-5 - clearing
	cout <<"\n";
	cout << "Using the clear function: " << endl;
	strDeque.clear();
	strDeque.display();
	cout <<"\n";
	strDeque.ddisplay();
	
	return 0;
}
