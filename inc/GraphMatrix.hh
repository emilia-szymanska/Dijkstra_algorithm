#ifndef GRAPHMATRIX_HH
#define GRAPMATRIX_HH

#include "list.hh"
#include "Pair.hh"

/*template <typename T>
struct Pair
{
	T first;
	T second;
	Pair(T element1 = T(0), T element2 = T(0)) {first = element1; second = element2;};

};
#include "../src/GraphMatrix.cpp"
*/

class GraphMatrix
{
	bool ** V;		//2-dimensions table of information about adjacency 
	int ** E;		//2-dimensions table of edges' values regarding V
	unsigned int size;

	public:
		GraphMatrix(unsigned int number_vertex);
		~GraphMatrix();
		bool areAdjacent(int v, int w);
		void insertEdge(int v, int w, int o);
		List<Pair<int> > incidentEdges(int v);
		int Size() {return this->size;}
			
};


#endif
