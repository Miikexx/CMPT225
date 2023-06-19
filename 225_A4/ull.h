/*
Header file for unrolled linked list
*/


#ifndef ULL_H
#define ULL_H
#include <string>
#define ARRSIZE 10

class ULListStr
{
public:
    struct Item
    {
        int val[ARRSIZE];
        size_t first, last;
        Item *prev;
        Item *next;

        Item()
        {
            first = last = 0;
            prev = next = NULL;
        }
    };

    ULListStr()
    {
        head_ = NULL;
        tail_ = NULL;
        size_ = 0;
    }
    bool empty() const
    {
        return size_ == 0;
    }

    void push_front(const int &val)
    {
        if (empty())
        { //no items
            Item *it = new Item();
            head_ = it;
            tail_ = it;
            it->val[0] = val;
            it->last++;
        }
        else if (head_->first == 0)
        { //head full
            Item *it = new Item();
            it->next = head_;
            head_->prev = it;
            head_ = it;
            it->val[ARRSIZE - 1] = val;
            it->last = ARRSIZE;
            it->first = ARRSIZE - 1;
        }
        else
        { //head not full
            head_->val[head_->first - 1] = val;
            head_->first--;
        }
        size_++;
    }
    void traverse()
    {
        Item *currentNode = head_;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
    }

private:
    Item *head_;
    Item *tail_;
    size_t size_;
};
#endif
