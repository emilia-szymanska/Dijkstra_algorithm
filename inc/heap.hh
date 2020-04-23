#ifndef HEAP
#define HEAP

#include <iostream>
using namespace std;

	
template <typename T>
void swapping (T & a, T & b);

template <typename T>
struct Heap
{
	T * table;
	unsigned int last_index;
	unsigned int max_size;

	Heap()
	{
		table = new T [32 + 1];
	        max_size = 32;
		last_index = 0;	
	}

	~Heap()
	{
		delete [] table;
	}
	
	void takeFromHeap ();

	void addToHeap (const T & object);

	T seeRoot ()
	{
		if (last_index != 0) return table[1];
	}	

	bool isEmpty ()
	{
		if(last_index == 0) return true;
		else return false;
	}

};	

#include "../src/heap.cpp"

#endif

