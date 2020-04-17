#ifndef GRAPH_HH
#define GRAPH_HH

#include "list.hh"

template <typename T>
struct pair
{
	T first;
	T second;
	pair(T element1, T element2) {first = element1; second = element2;};
};


template <typename T>
class Graph
{
	public:	
		struct Vertex 
		{
			T vertex_element;
			List<&Edge> neighbour_edges;		//list of references to neigbour edges
			List<&Vertex>::node * position_on_list;	//pointer to vertex node position on list
		};

		struct Edge
		{
			T edge_element;
			Vertex & vertex_begin;			//reference to vertex_begin; no need to add lists of incidences as a vertex has a list to neighbour edges 
			Vertex & vertex_end;			//reference to vertex_end
			List<&Edge>::node * position_on_list;	//pointer to edge node position on list
		};

		pair<Vertex> endVertices(Edge e);
		Vertex opposite(Vertex v, Edge e);
		bool areAdjacent(Vertex v, Vertex w);
		void replace(Vertex v, T x);
		void replace(Edge e, T x);
		void insertVertex(T o);
		void insertEdge(Vertex v, Vertex w, T o);
		void removeVertex(Vertex v);
		void removeEdge (Edge e);
		List<Edges> incidentEdges(Vertex v);
		List<Vertex> vertices();
		List<Edge> edges();
		
	private:
		List<&Edge> edge_list;
		List<&Vertex> vertex_list;
	
};

#include "../src/graph.cpp"

#endif
