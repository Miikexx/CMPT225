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
		
	// Part two of the experiment:
	
	//create trees:
	BinarySearchTree<int> largebst;
	AvlTree<int> largeavl;
	
	int bstInsert =0;
	
	clock_t start;
	clock_t finish;
	start = clock();
	
	for(int i=0; i < 20000; i++)
	{
		largebst.insert(bstInsert);
		bstInsert++;
	}
	finish = clock();
	double time_taken = elapsed_time(start, finish);
	cout << "Insertion time taken for bst: " << time_taken << endl;
	int avgKeyDepth =0;
	
	for(int i=0; i < 20000; i++)
	{
		avgKeyDepth += largebst.depth(i);
	}
	const int nodeamount = 20000;
	avgKeyDepth = avgKeyDepth / nodeamount;
	cout << "Average key depth for this BST is: " << avgKeyDepth << endl;
	
	// bst - membership check
	
	
	
	// min max and mean times for memebership checks
	clock_t start1_1;
	clock_t finish1_1;
	
	int depth_max;
	int depth_min;
	double time_max;
	double time_min;
	double present;
	double time_total;
	for(int i=0; i <20000; i++)
	{
		start1_1 = clock();
		
		
		largebst.contains(i);
		finish1_1 = clock();
		
		present = elapsed_time(start1_1, finish1_1);
		time_total += present;
		// Minimum time + minimum depth computation:
		
		if(time_min == 0)
		{
			time_min = present;
			depth_min = largebst.depth(i);
		}
		
		else
		{
			if(time_min == present ||time_min > present)
			{
				time_min = present;
				depth_min = largebst.depth(i);
			}
		}
		
		//Max time + max depth computation:
		if(time_max == 0)
		{
			time_max = present;
			depth_max = largebst.depth(i);
		}
		else
		{
			if(time_max == present || time_max < present)
			{
				time_max = present;
				depth_max = largebst.depth(i);
			}
		}
		
	}
	// average time
	double time_avg = time_total / nodeamount;
	
	
	
	//data display:
	cout << "Time: " << endl;
	cout << "Minimum time: " << time_min << endl;
	cout << "Maximum time: " << time_max << endl;
	cout << "Average time: " << time_avg << endl;
	
	cout << "Depth: " << endl;
	cout << "Minimum depth: " << depth_min << endl;
	cout << "Maximum depth: " << depth_max << endl;
	cout << "Average depth: " << avgKeyDepth << endl;
	
	//height:
	cout << "Height of the bst tree: " << largebst.height() << endl;
	cout << "//////////////////////////////////////////////////////////" << endl;
	//
	//AVL:
	int avlInsert = 0;
	
	clock_t start2;
	clock_t finish2;
	start2 = clock();
	
	for(int i=0; i< 20000; i++)
	{
		largeavl.insert(avlInsert);
		avlInsert++;
	}
	finish2 = clock();
	double time_taken2 = elapsed_time(start2, finish2);
	cout << "Insertion time taken for avl tree: " << time_taken2 << endl;
	
	int avgKeyDepth2 =0;
	
	for(int i=0; i < 20000; i++)
	{
		avgKeyDepth2 += largeavl.depth(i);
	}
	//avg key depth
	avgKeyDepth2 = avgKeyDepth2 / nodeamount;
	cout << "Average key depth for this Avl tree is: " << avgKeyDepth2 << endl;
	
	// avl membership check
		
	// min max and mean times for memebership checks
	clock_t start2_1;
	clock_t finish2_1;
	int depth_max2;
	int depth_min2;
	double time_max2;
	double time_min2;
	double present2;
	double time_total2;
	for(int i=0; i <20000; i++)
	{
		start2_1 = clock();
		
		
		largeavl.contains(i);
		finish2_1 = clock();
		
		present2 = elapsed_time(start2_1, finish2_1);
		time_total2 += present2;
		// Minimum time + minimum depth computation:
		
		if(time_min2 == 0)
		{
			time_min2 = present2;
			depth_min2 = largeavl.depth(i);
		}
		
		else
		{
			if(time_min2 == present2 ||time_min2 > present2)
			{
				time_min2 = present2;
				depth_min2 = largeavl.depth(i);
			}
		}
		//Max time + max depth computation:
		if(time_max2 == 0)
		{
			time_max2 = present2;
			depth_max2 = largeavl.depth(i);
		}
		else
		{
			if(time_max2 == present2 || time_max2 < present2)
			{
				time_max2 = present2;
				depth_max2 = largeavl.depth(i);
			}
		}
		
	}
	// average time
	double time_avg2 = time_total2 / nodeamount;
	
	
	
	//data display:
	cout << "Time: " << endl;
	cout << "Minimum time: " << time_min2 << endl;
	cout << "Maximum time: " << time_max2 << endl;
	cout << "Average time: " << time_avg2 << endl;
	
	cout << "Depth: " << endl;
	cout << "Minimum depth: " << depth_min2 << endl;
	cout << "Maximum depth: " << depth_max2 << endl;
	cout << "Average depth: " << avgKeyDepth2 << endl;
	
	// height
	cout << "Height of the avl tree: " << largeavl.height() << endl;
	


	
	return 0;
}
