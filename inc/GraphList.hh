#ifndef GRAPHLIST_HH
#define GRAPHLIST_HH

#include "list.hh"

template <typename T>
struct Pair
{
	T first;
	T second;
	Pair(T element1 = T(0), T element2 = T(0)) {first = element1; second = element2;};
};


class GraphList
{
	List<Pair<int> > * V;		//table of lists of vertex-edge pairs
	unsigned int size;

	public:
		GraphList(unsigned int number_vertex) {this->size = number_vertex; this->V = new List<Pair<int> > [number_vertex];}
		~GraphList()
		{
			for(unsigned int i = 0; i < this->size; i++) V[i].~List<Pair<int> >();
			delete [] V;	
		}
		bool areAdjacent(int v, int w);
		void insertEdge(int v, int w, int o);
		List<Pair<int> > & incidentEdges(int v);
		int Size() {return this->size;}
			
};

#include "../src/GraphList.cpp"

#endif
