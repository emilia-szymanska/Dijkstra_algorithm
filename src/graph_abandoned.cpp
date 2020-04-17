/*		struct Vertex 
		{
			T vertex_element;
			List<&Edge> neighbour_edges;		//list of references to neigbour edges
			List<&Vertex>::node * position_in_list;	//pointer to vertex node position on list
		};

		struct Edge
		{
			T edge_element;
			Vertex & vertex_begin;	 
			Vertex & vertex_end;			//reference to vertex_end
			List<&Edge>::node * position_in_list;	//pointer to edge node position on list
		};*/

template <typename T>
pair<Vertex> Graph<T>::endVertices(Edge e)
{
	pair<Vertex> result;
	result.first = e.vertex_begin;
	result.second = e.vertex_end;
	return result;	
}

template <typename T>		
Vertex Graph<T>::opposite(Vertex v, Edge e)
{
	if(e.vertex_begin == v) return e.vertex_end;
	else return e.vertex_begin;
}

template <typename T>
bool Graph<T>::areAdjacent(Vertex v, Vertex w)
{
/*	for(i = 0; i < v.neighbour_edges.size(); i++)
		if(v.neighbour_edges[i].vertex_begin == w || v.neighbour_edges[i].vertex_end == w) return true;
*/	return false;
}

template <typename T>
void Graph<T>::replace(Vertex v, T x);


template <typename T>
void Graph<T>::replace(Edge e, T x);


template <typename T>
void Graph<T>::insertVertex(T o);


template <typename T>
void Graph<T>::insertEdge(Vertex v, Vertex w, T o);


template <typename T>
void Graph<T>::removeVertex(Vertex v);


template <typename T>
void Graph<T>::removeEdge (Edge e);


template <typename T>
List<Edges> Graph<T>::incidentEdges(Vertex v);


template <typename T>
List<Vertex> Graph<T>::vertices();


template <typename T>
List<Edge> Graph<T>::edges();

