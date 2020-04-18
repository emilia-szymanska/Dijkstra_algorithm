#include "../inc/GraphMatrix.hh"

GraphMatrix::GraphMatrix(unsigned int number_vertex) 
{
	this->size = number_vertex; 

	this->V = new bool * [number_vertex];
	for(unsigned int i = 0; i < this->size; i++)
		this->V[i] = new bool [number_vertex];
	
	this->E = new int * [number_vertex];
	for(unsigned int i = 0; i < this->size; i++)
		this->E[i] = new int [number_vertex];
	
	for(unsigned int i = 0; i < this->size; i++)
		for(unsigned int j = 0; j < this->size; j++)
			V[i][j] = false;

}

GraphMatrix::~GraphMatrix()
{
	for(unsigned int i = 0; i < this->size; i++)
		delete [] V[i];
	delete [] V;	

	for(unsigned int i = 0; i < this->size; i++)
		delete [] E[i];
	delete [] E;	

}


bool GraphMatrix::areAdjacent(int v, int w)
{
	return V[v][w];  		
}


void GraphMatrix::insertEdge(int v, int w, int o)
{
	V[v][w] = true;
	E[v][w] = o;
	return;
}
		
List<Pair<int> > GraphMatrix::incidentEdges(int v)
{
	List<Pair<int> > result;
	for(unsigned int i = 0; i < this->size; i++)
		if (V[v][i] == true) result.push_back(Pair<int>(i,E[v][i]));

	return result;	
}
		
