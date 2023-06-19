#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>

using namespace std;

template <typename Object>
class Deque 
{
  public:
    Deque()
      {  
         theCapacity = 8 ;
         objects = new Object[ theCapacity ]; 
         theSize = 0 ;
         front = 0 ; 
         back = 0 ; 
      }
      
    ~Deque( )
      { delete [ ] objects; }

    bool empty( ) const  { return size( ) == 0; }
    int size( ) const { return theSize; }
    
    void clear( ){
        for(int i=0; i < theCapacity; i++)
        {
        	dequeue();
        }
        
        const int defaultSize =0;
        
        theSize = defaultSize;
        
    }

    void reserve( int newCapacity )
    {
    	
        if(newCapacity > theSize)
        {
	
		Object *newDeque = new Object[newCapacity];
		//Adjust the new back:
		back = theCapacity;
		
		//accumulator variable:
		int tally =0;
		
		if(front ==0)
		{
			int frontVal;
			for(frontVal=front; frontVal < back; frontVal++)
			{
				newDeque[frontVal] = objects[frontVal];
			} 
		}
		else
		{
			
			int frontVal2;
			for(frontVal2=front; frontVal2 < theCapacity ; frontVal2++)
			{
				newDeque[tally] = objects[frontVal2];
				//increment tally by 1:
				tally++;
			}
		}
		for(int j=0; j < back ;j++)
		{
			newDeque[tally] = objects[j];
			//increment tally by 1:
			tally++;
		}
		
		
		Object *temp = objects;
		objects = newDeque;
		//free the memory:
		delete [ ] temp; 
		
		//Adjust front value and capacity
		front =0;
		theCapacity = newCapacity;
		
        }
        
        //no changes neccessary if newCapacity is smaller or equal to the currentCapacity
        else
        {
        	return;
        }
    }

    // Operations 

    void enqueue( const Object & x )// Insert a new object at the back 
    {
        if( theSize == theCapacity ) reserve( 2 * theCapacity + 1 );
        objects[ back ] = x ; 
        back = (back+1) % theCapacity ;
        theSize++;
    }

    void jump( const Object & x )// Insert a new object at the front 
    {
        // Implement this
        if( theSize == theCapacity ) 
        {
        	reserve(2* theCapacity + 1);
        }
        else if(front ==-1 && back == -1)
        {
        	const int defaultEmptyVal =0;
        	front = defaultEmptyVal;
        	back = defaultEmptyVal;
        	objects[front] = x;
        }
        else if( front == 0)
        {
        	front = theCapacity -1;
        	objects[front] = x;
        }
        else
        {
        	front--;
        	objects[front] = x;
        }
        theSize++;
        
        return;
    }

    Object dequeue( )// Remove and return the object at the front 
    {
        theSize--;
        Object temp = objects[front];
        front = (front+1) % theCapacity ;
        return temp ;
    }

    Object eject( )// Remove and return the object at the back 
    {
        Object temp = objects[back];
        back = (back-1 == -1);
        theSize--;
        return temp;
    }

    void display() const // print out the contents of the deque
    {
       cout << "size=" << theSize << endl;
       cout << "< " ;
       for(int i=0; i <theSize; i++)
       {
       	int temp = (front+i) % theCapacity;
       	cout << objects[temp] << " , ";
       }
       cout << ">" << endl;
    }

    void ddisplay() const // print out the contents of the objects 
    // array, and relevant variables, for debugging or verifying 
    // correctness. 
    {
        cout << "capacity=" << theCapacity << ", size=" << theSize << endl;
        cout << "Front index position: " << front << " Back index position: " <<back << endl;
        cout <<"[ ";
        for(int i=0; i < theCapacity; i++)
        {
        	cout << i << "=" << objects[i] << ", ";
        }
        cout << "] " << endl;
    }

	int& operator[](int num)
	{
		// 2 scenarios: when back> front and when front >= back
		if (back > front)
		{
			for(int i=0; i< back; i++)
			{
				if(i == num) return objects[i];
			}
		}
		
		if (front >= back)
		{
			int tally =0;
			for(int i = front; i < theCapacity; i++)
			{
				if(tally == num) return objects[i];
			
			tally++;
			}
			
			for(int j=0; j < back; j++)
			{
				if(tally ==0) return objects[j];
				tally++;
			}
		}
		
	};

  private:
    int theSize;
    int front;
    int back;
    int theCapacity;
    Object * objects;
};

#endif
