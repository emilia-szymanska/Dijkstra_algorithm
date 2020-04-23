#ifndef DIJKSTRA_HH
#define DIJKSTRA_HH

#include "heap.hh"

struct Dijkstra_results
{
	unsigned int Size;
	int * distance;
	int * previous;
	
	Dijkstra_results(int Size) 
	{
		this->Size = Size;
		this->distance = new int [Size];
		this->previous = new int [Size];
	}

	~Dijkstra_results() 
	{
		delete [] distance;
		delete [] previous;
	}
};

template <class T>
Dijkstra_results dijkstra_algorithm(T & graph, int vertex);

#include "../src/Dijkstra.cpp"

#endif
