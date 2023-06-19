/*
    Filename: PQdemo.cpp
    Author: Mike Kim
    Description: This is the testing file for functions in PQ.h
*/
#include <algorithm>
#include <vector>

#include <iostream>
#include "PQ.h"
#include "dsexceptions.h"


int main( void )
{
    PQ<char> pq1; // priority queue with inserted elements
    PQ<char> pq2; // empty priority queue built for testing
    // Insertion process:

    pq1.insert('a',0);
    pq1.insert('b',1);
    pq1.insert('c',2);
    pq1.insert('d',3);
    pq1.insert('e',4);
    pq1.insert('f',5);
    pq1.insert('g',6);
    pq1.insert('h',7);
    pq1.insert('i',8);
    pq1.insert('j',9);
    pq1.insert('k',10);
    
    // Test 1: ---
    cout << "----------------------------" << endl;
    cout << "Test 1: Testing the insertion function and public_displayheap function: " << endl;
    cout << "Display: " << endl;
    pq1.public_displayHeap();
    cout << "----------------------------" << endl;

    // Test 2: ---
    cout << "----------------------------" << endl;
    cout << "Test 2: Testing the deleteMin function: " << endl;
    cout << "Performing deleteMin on pq1... " << endl;
    cout << "value returned: " << pq1.deleteMin() << endl;
    cout << "----------------------------" << endl;

    // Test 3: ---
    cout << "----------------------------" << endl;
    cout << "Test 3: Testing the findMin function: " << endl;
    cout << "Returning a task ID with the smallest priority for PQ1: ";
    cout << pq1.findMin() << endl;
    cout << "----------------------------" << endl;

    // Test 4:
    cout << "----------------------------" << endl;
    cout << "Test 4: Testing the updatePriority function: " << endl;
    cout << "Giving 'h' a new priority of 3: " << endl;
    pq1.updatePriority('h',3);
    cout << "Displaying the new updated heap with adjusted priority: " << endl;
    pq1.public_displayHeap();
    cout << "----------------------------" << endl;

    // Test 5: --- 
    cout << "----------------------------" << endl;
    cout << "Test 5: Testing the isEmpty function: " << endl;
    cout << "For pq1 (expected result = false): " << pq1.isEmpty() << endl;
    cout << "For pq2 (expected result = true): " << pq2.isEmpty() << endl;
    cout << "----------------------------" << endl;

    // Test 6: ---
    cout << "----------------------------" << endl;
    cout << "Test 6: Testing the size function: " << endl;
    cout << "The size of pq1: " << pq1.size() << endl;
    cout << "The size of pq2: " << pq2.size() << endl;
    cout << "----------------------------" << endl;

    // Test 7: ---
    cout << "----------------------------" << endl;
    cout << "Test 7: Testing the insertion function: " << endl;
    cout << "Inserting element 'z' with the priority value of 11: " << endl;
    pq1.insert('z', 11);
    cout << "inserting element 'y' with the priority value of 8: " << endl;
    pq1.insert('y',8);
    cout << "Displaying the updated heap after the insertion" << endl;
    pq1.public_displayHeap();
    cout << "----------------------------" << endl;
    
    // Test 8: ---
    cout << "----------------------------" << endl;
    cout << "Test 8: Testing the makeEmpty function: " << endl;
    cout << "Current status of pq1 (true indicates that it is empty) : " << pq1.isEmpty() << endl;
    cout << "Emptying out the pq1 then confirming the emptyness of the priority queue: " << endl;
    pq1.makeEmpty();
    cout << "Updated status of pq1 (true indicates that it is empty) : " << pq1.isEmpty() <<endl;
    cout << "----------------------------" << endl;

    cout << "\n" << endl;
    cout << "End of test file. All test cases completed." << endl;
    
    return 0;
}
