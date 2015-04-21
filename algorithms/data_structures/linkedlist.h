//implementing a linked list to make sure I still can
#ifndef __Linkedlist__
#define __Linkedlist__

#include <iostream>

using namespace std;

template <typename Key, typename Value>
class LinkedList 
{
    public:
 
        LinkedList();
        bool insert(Key k, Value v);
        bool remove(Key k);
        bool contains(Key k);
        Value getValue(Key k);
        bool isEmpty();
 
    private:

        template<typename nodeKey, typename nodeValue>
        struct node
        {
            Key key;
            Value value;
            node<Key, Value>* next;
            node<Key, Value>* prev;
        };        
        
        node<Key, Value>* _head;

};

template <typename Key, typename Value>
Value LinkedList<Key, Value>::getValue(Key k)
{
    node<Key, Value>* nodeptr = _head;

    while (nodeptr)
    {
        if (nodeptr->key == k)
            return nodeptr->value;
        else
            nodeptr = nodeptr->next;
    }

    return 0;

}

template <typename Key, typename Value>
LinkedList<Key, Value>::LinkedList()
{
    _head = NULL;
}


template <typename Key, typename Value>
bool LinkedList<Key, Value>::insert(Key k, Value v)
{
    if (_head == NULL)
    {
        
        _head = new node<Key, Value>;
        _head->key = k;
        _head->value = v;
        _head->prev = NULL;
        _head->next = NULL;
        return true;
    }

    node<Key, Value>* nodeptr = _head;

    while (nodeptr->next)
        nodeptr = nodeptr->next;

    nodeptr->next = new node<Key, Value>;
    nodeptr->next->prev = nodeptr;
    nodeptr->next->key = k;
    nodeptr->next->value = v;
    nodeptr->next->next = NULL;
    return true;

}

template <typename Key, typename Value>
bool LinkedList<Key, Value>::remove(Key k)
{
    node<Key, Value>* nodeptr = _head;

    while (nodeptr)
    {
        if (nodeptr->key == k)
        {
            if (nodeptr == _head)
            {
                if (nodeptr->next == NULL)
                {
                    delete nodeptr;
                    _head = NULL;
                    return true;
                }
                _head = nodeptr->next;
                _head->prev = NULL;
                delete nodeptr;
                return true;
            }

            nodeptr->prev->next = nodeptr->next;
            nodeptr->next->prev = nodeptr->prev;
            delete nodeptr;
            return true;
        }
        else
            nodeptr = nodeptr->next;
    }

    return false;

}

template <typename Key, typename Value>
bool LinkedList<Key, Value>::contains(Key k)
{
    node<Key, Value>* nodeptr = _head;

    while (nodeptr)
    {
        if (nodeptr->key == k)
            return true;
        else
            nodeptr = nodeptr->next;
    }
    return false;
    
}

template <typename Key, typename Value>
bool LinkedList<Key, Value>::isEmpty()
{
    return !_head;
}




#endif
