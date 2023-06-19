/*
  Assignment #3
  Author: Mike
  Date (Last Modified): November 27th, 2022
*/

#ifndef PQ_H
#define PQ_H


#include <algorithm>
#include <vector>

#include <iostream>

#include "dsexceptions.h"



using namespace std;


// PQ class
//
// Constructors:
// PQ --> constructs a new empty queue
// PQ( tasks, priorities ) --> constructs a new queue with a given set of task IDs and priorities
// ******************PUBLIC OPERATIONS*********************
// void insert( x, p )       --> Insert task ID x with priority p
// ID findMin( )  --> Return a task ID with smallest priority, without removing it
// ID deleteMin( )   --> Remove and return a task ID with smallest priority
// void updatePriority( x, p )   --> Changes priority of ID x to p (if x not in PQ, inserts x);
// bool isEmpty( )   --> Return true if empty; else false
// int size() --> return the number of task IDs in the queue
// void makeEmpty( )  --> Remove all task IDs (and their priorities)
// ******************ERRORS********************************
// Throws UnderflowException as warranted

template <typename ID>
// ID is the type of task IDs to be used; the type must be Comparable (i.e., have < defined), so IDs can be AVL Tree keys.
class PQ
{

public:
  // Node for Avl tree is being nested:

  struct AvlNode
  {
    ID element;
    AvlNode *left;
    AvlNode *right;
    int height = 0;
    int index;

    AvlNode(const ID &ele, AvlNode *lt, AvlNode *rt, int h, int idx)
        : element{ele}, left{lt}, right{rt}, height{h}, index{idx} {}

    AvlNode(ID &&ele, AvlNode *lt, AvlNode *rt, int h, int idx)
        : element{std::move(ele)}, left{lt}, right{rt}, height{h}, index{idx} {}
  };

  // Avl tree class is nested inside the priority queue
  class AvlTree
  {
  public:
    AvlTree( ) : root{ nullptr }
    {
    }

    AvlTree(const AvlTree & rhs) : root{ nullptr }
    {
      root = clone( rhs.root );
    }

    AvlTree(AvlTree && rhs) : root{ rhs.root }
    {
      rhs.root = nullptr;
    }

    ~AvlTree()
    {
      makeEmpty();
    }

    /**
     * Deep copy.
     */
    AvlTree & operator=(const AvlTree & rhs)
    {
      AvlTree copy = rhs;
      std::swap( *this, copy );
      return *this;
    }

    /**
     * Move.
     */
    AvlTree & operator=( AvlTree  && rhs )
    {
      std::swap( root, rhs.root );

      return *this;
    }

    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const ID &findMin() const
    {
      if ( isEmpty() )
        throw UnderflowException{};
      return findMin( root )->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const ID &findMax() const
    {
      if ( isEmpty() )
        throw UnderflowException{};
      return findMax( root )->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains( const ID & x ) const
    {
      return contains( x, root );
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     */
    bool isEmpty() const
    {
      return root == nullptr;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree() const
    {
      if ( isEmpty() )
        cout << "Empty tree" << endl;
      else
        printTree( root );
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty()
    {
      makeEmpty( root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( const ID & x )
    {
      insert( x, root );
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    void insert( ID && x )
    {
      insert( std::move(x), root );
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove( const ID & x )
    {
      remove( x, root );
    }

    void setPrio(const ID &x)
    {
      setPrio( x, root );
    }

    AvlNode *find(const ID &x)
    {
      return find(x, root);
    }

  private:
    AvlNode *root;

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */

    void insert( const ID & x, AvlNode *&t )
    {
      if (t == nullptr)
        t = new AvlNode{x, nullptr, nullptr, 0, 0};
      else if (x < t->element)
        insert(x, t->left);
      else if (t->element < x)
        insert(x, t->right);

      balance(t);
    }

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void insert(ID && x, AvlNode *&t)
    {
      if (t == nullptr)
        t = new AvlNode{std::move(x), nullptr, nullptr, 0, 0};
      else if (x < t->element)
        insert(std::move(x), t->left);
      else if (t->element < x)
        insert(std::move(x), t->right);

      balance(t);
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove( const ID &x, AvlNode *&t )
    {
      if (t == nullptr)
        return; // Item not found; do nothing

      if (x < t->element)
        remove(x, t->left);
      else if (t->element < x)
        remove(x, t->right);
      else if (t->left != nullptr && t->right != nullptr) // Two children
      {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
      }
      else
      {
        AvlNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
      }

      balance(t);
    }

    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance(AvlNode *&t)
    {
      if (t == nullptr)
        return;

      if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
      {
        if (height(t->left->left) >= height(t->left->right))
        {
          rotateWithLeftChild(t);
        }
        else
        {
          doubleWithLeftChild(t);
        }
      }
      else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE)
      {
        if (height(t->right->right) >= height(t->right->left))
        {
          rotateWithRightChild(t);
        }
        else
        {
          doubleWithRightChild(t);
        }
      }

      t->height = max(height(t->left), height(t->right)) + 1;
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    AvlNode *findMin(AvlNode *t) const
    {
      if (t == nullptr)
        return nullptr;
      if (t->left == nullptr)
        return t;
      return findMin(t->left);
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    AvlNode *findMax(AvlNode *t) const
    {
      if (t != nullptr)
        while (t->right != nullptr)
          t = t->right;
      return t;
    }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains(const ID &x, AvlNode *t) const
    {
      if (t == nullptr)
        return false;
      else if (x < t->element)
        return contains(x, t->left);
      else if (t->element < x)
        return contains(x, t->right);
      else
        return true; // Match
    }
    /****** NONRECURSIVE VERSION*************************
    bool contains( const Comparable & x, AvlNode *t ) const
    {
        while( t != nullptr )
            if( x < t->element )
                t = t->left;
            else if( t->element < x )
                t = t->right;
            else
                return true;    // Match

        return false;   // No match
    }
*****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty(AvlNode *&t)
    {
      if (t != nullptr)
      {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
      }
      t = nullptr;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree(AvlNode *t) const
    {
      if (t != nullptr)
      {
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
      }
    }

    /**
     * Internal method to clone subtree.
     */
    AvlNode *clone(AvlNode *t) const
    {
      if (t == nullptr)
        return nullptr;
      else
        return new AvlNode{t->element, clone(t->left), clone(t->right), t->height};
    }
    // Avl manipulations
    /**
     * Return the height of node t or -1 if nullptr.
     */
    int height(AvlNode *t) const
    {
      return t == nullptr ? -1 : t->height;
    }

    int max(int lhs, int rhs) const
    {
      return lhs > rhs ? lhs : rhs;
    }

    AvlNode *find(const ID &x, AvlNode *t)
    {
      if (t == nullptr)
      {
        return t;
      }
      if (t->element == x)
      {
        return t;
      }
      if (t->element < x)
      {
        return find(x, t->right);
      }
      if (t->element > x)
      {
        return find(x, t->left);
      }

      else
      {
        return nullptr;
      }
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild(AvlNode *&k2)
    {
      AvlNode *k1 = k2->left;
      k2->left = k1->right;
      k1->right = k2;
      k2->height = max(height(k2->left), height(k2->right)) + 1;
      k1->height = max(height(k1->left), k2->height) + 1;
      k2 = k1;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild(AvlNode *&k1)
    {
      AvlNode *k2 = k1->right;
      k1->right = k2->left;
      k2->left = k1;
      k1->height = max(height(k1->left), height(k1->right)) + 1;
      k2->height = max(height(k2->right), k1->height) + 1;
      k1 = k2;
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild(AvlNode *&k3)
    {
      rotateWithRightChild(k3->left);
      rotateWithLeftChild(k3);
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    void doubleWithRightChild(AvlNode *&k1)
    {
      rotateWithLeftChild(k1->right);
      rotateWithRightChild(k1);
    }
  };

  //-----------------------------------------------
  //End of AVL tree class

  // Constructor (brand new priority queue that is empty)
  // - Done
PQ()
  {
    AvlTree binaryHeap_tree;
    vector<pair<int, AvlNode *>> heap;
    heap_size = 0;
    //ID the_id;  
  }

  // Constructor
  // Initializes a new PQ with a given set of tasks IDs and priorities
  //      priority[i] is the priority for ID task[i]

  PQ(const std::vector<ID> &tasks, const std::vector<int> &priorities)
  {
    // set the size of the heap to 0 first:
    heap_size = 0;

    for (int i = 0; i < tasks.size(); i++)
    {
      // declare a variable to keep track of updated priority
      int updated_priority = priorities[i];
      cout << updated_priority << endl;
      //perform insertion
      insert(tasks[i], updated_priority);
    }
  }

  // Emptiness check
  bool isEmpty() const
  {

    // true if heap is empty
    if(heap.empty() && binaryHeap_tree.isEmpty())
    {
      return true;
    }

    // false otherwise
    return false;
    
  }


  // Deletes and Returns a task ID with minimum priority---------------------------------
  //    Throws exception if queue is empty
  const ID &deleteMin() 
  {
    if(heap.empty())
    {
    	throw UnderflowException{ };
    }
    
    AvlNode *node = heap[0].second;
    the_id = findMin();
    heap.erase(heap.begin());
    binaryHeap_tree.remove(node -> element);
    heap_size--;
    percolateDown(0);
    return the_id;
  }

  // Returns an ID with minimum priority without removing it
  //     Throws exception if queue is empty
  const ID &findMin() const
  {
    //Accounting for a case when heap is empty
    if(heap.empty()) 
    {
    	throw UnderflowException{ };
    }
    
    else
    {
    	AvlNode *node = heap[0].second;
    	return node->element;
    }
    
  }
  // Insert ID x with priority p.
  void insert(const ID &x, int p)
  {

    int size_variable = heap_size;
    
    // AVL operations
    binaryHeap_tree.insert(x);
    AvlNode *temp_var = binaryHeap_tree.find(x);
    temp_var->index = p;
    
    // Operations being done on heap
    heap.push_back(make_pair(p, temp_var));
    int value = size_variable;
    percolateUp(value);
    heap_size++;
    
    int a;

    for(int x =0; x < heap_size; x++)
    {
        if(heap[x].second == temp_var) a = x;
    }
    
    temp_var->index = a;
  }

  // Update the priority of ID x to p
  //    Inserts x with p if s not already in the queue
  void updatePriority(const ID &x, int p) 
  {
    if(binaryHeap_tree.contains(x))
    {
        int priority_value;
        AvlNode *tempVar = binaryHeap_tree.find(x);
        priority_value = tempVar->index;

        if(p > heap[priority_value].first)
        {
            heap[priority_value].first = p;
            percolateDown(priority_value);
        }
        
        if(p < heap[priority_value].first)
        {
            heap[priority_value].first = p;
            //special percolateup procedure for updatepriority operation:
            updatePrio_percolateUp(priority_value); 
            
        }
    }
    else
    {
        insert(x,p);
    }

    


  }

  // Return the number of task IDs in the queue
  int size() const
  {
    //simply return the value of heap_size as it is
    //keeping track of the size
    return heap_size;
  }

  // Delete all IDs from the PQ
  void makeEmpty()
  {
	binaryHeap_tree.makeEmpty();
	heap.clear();
	heap_size =0;	
  }

  void public_displayHeap()
  {
    displayHeap();
  }

  void displayAvl()
  {
    binaryHeap_tree.printTree();
  }

private:
  // private class for Binary heap tree
  AvlTree binaryHeap_tree;
  
  // a vector of pairs to represent our heap
  vector<pair<int, AvlNode *>> heap;
  // size of our heap/array
  int heap_size;

  // ID
  ID the_id;
  
  void percolateUp(int indexVal)
  {
    int percolate_value = (indexVal - 1) / 2;
    while (indexVal > 0 && heap[percolate_value].first > heap[indexVal].first)
    {
      swap(heap[percolate_value], heap[indexVal]);
      indexVal = percolate_value;
      percolate_value = ((indexVal - 1) / 2);
    }
  }

  void updatePrio_percolateUp(int indexVal)
  {
    int a;
    a = ((indexVal -1) / 2);
    
    while(heap[indexVal].first < heap[a].first && indexVal > 0)
    {
        AvlNode *node1 = heap[indexVal].second;
        AvlNode *node2 = heap[a].second;

        swap(heap[a], heap[indexVal]);

        int tempVariable = node1->index;
        node1->index = node2->index;
        node2->index = tempVariable;
        indexVal = a;

        a = (indexVal - 1) / 2;
    }

  }
  
  void percolateDown(int indexVal)
  {
    long unsigned int b = indexVal;
    int childNode;
    //while left child is smaller than the size of the heap
    while((2*b +1) < heap.size()) 
    {
        childNode = (2*b + 1);
        if(heap[2*b +2].first < heap[2*b +1].first && (2*b +2) < heap.size()) 
        {
        	childNode = (2*b +2);
	}
	
        AvlNode *node1 = heap[indexVal].second;
        AvlNode *node2 = heap[childNode].second;

        if(heap[b].first > heap[childNode].first)
        {
            swap(heap[childNode], heap[b]);
            //temp variable to hold the value for swapping
            int tempVariable = node1->index;

            node1->index = node2->index;
            node2->index = tempVariable;
        }

        if(heap[b].first < heap[childNode].first) break;

    }
    return;
  }

  void displayHeap()
  {
    for (long unsigned int i = 0; i < heap.size(); i++)
    {
      cout << heap[i].first << ", " << heap[i].second << endl;
    }

    return;
  }
  void printSize()
  {
    cout << heap_size << endl;

    return;
  }
};
#endif
