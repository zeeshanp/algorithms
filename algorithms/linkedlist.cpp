//implementing a linked list to make sure I still can

#include <iostream>
using namespace std;

template <class T>
class node
{
    public:
        node(T elem)
        {
            data = elem;
        }

        void setNext(node* next) { _next = next; }
        void setPrev(node* prev) { _prev = prev; }
        node<T>* getNext() { return _next; }
        node<T>* getPrev() { return _prev; }
    
    private:
        T _data;
        node<T>* _next;
        node<T>* _prev;
};

template <class T>
class linkedList 
{
    public:
        linkedList(T elem);
        bool insert(T elem);
        bool remove(T elem);
        bool isEmpty();
    private:
        node<T> _head;
        int _numElements;

};

template <class T>
linkedList<T>::linkedList(T elem)
{
    _numElements = 0;
}

template <class T>
bool linkedList<T>::insert()
{
    int count = _numElements;
    node<T> *nodeptr = &_head;
    while (count > 0)
    {
        nodeptr = nodeptr->getNext();
        count--;
    }
    nodeptr->get
}

template <class T>
bool linkedList<T>::remove()
{

}

template <class T>
bool linkedList<T>::isEmpty()
{
    return !_numElements;
}


