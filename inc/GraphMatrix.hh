#ifndef GRAPHMATRIX_HH
#define GRAPMATRIX_HH

#include "list.hh"
#include "Pair.hh"


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
