#ifndef __HASHTABLE__
#define __HASHTABLE__

#include "linkedlist.h"

// hash table of (key, value) pairs
// 

template<typename Key, typename Value>
class HashTable
{
	public:
		HashTable();
		~HashTable();
		bool insert(Key k, Value v);
		bool remove(Key k);
		bool isEmpty();


	private:
		int hash(Key k)
		{
			return (k % numBuckets);
		}
		int numBuckets;
		int numElements;
		LinkedList<Key, Value> buckets[numBuckets];

};

template<typename Key, typename Value>
HashTable<Key, Value>::Hashtable()
{
	numElements = 0;
	numBuckets = 7;   //pick a prime to reduce collisions
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::insert(Key k, Value v)
{
	int bucket = hash(k);
	buckets[bucket].insert(k, v);
	numElements++;
	return true;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::remove(Key k)
{
	int bucket = hash(k);
	if (buckets[bucket].remove(k,v))
	{
		numElements--;
		return true;
	}
	return false;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::isEmpty()
{
	return !numElements;
}

template<typename Key, typename Value>
HashTable<Key, Value>::HashTable()
{
	return;
}


#endif