template <class T>
Dijkstra_results dijkstra_algorithm(T & graph, int vertex)
{
	int v, dist, neighbour_index, neighbour_edge;
	unsigned int number_of_elements = graph.Size();
	Dijkstra_results result = Dijkstra_results(number_of_elements);			//putting results into special struct
	for(unsigned int i = 0; i < number_of_elements; i++)		// making ,,infinity'' values
	{	
		result.distance[i] = -1;
		result.previous[i] = -1;
	}

	result.distance[vertex] = 0;
	Heap<Pair<int> > Q = Heap<Pair<int> >();	
	Q.addToHeap(Pair<int>(0, vertex));
	while(!Q.isEmpty())						//Dijkstra's magic
	{
		dist = -Q.seeRoot().first;
		v = Q.seeRoot().second;
		Q.takeFromHeap();
		if(dist > result.distance[v]) continue;
		List<Pair<int> > neighbours = graph.incidentEdges(v);
		for (auto It = neighbours.begin(); It != neighbours.end(); It++)
		{
			
			neighbour_index = (*It).first;
			neighbour_edge = (*It).second;
			if(result.distance[neighbour_index] == -1 || result.distance[neighbour_index] > dist + neighbour_edge)
			{       	
				result.previous[neighbour_index] = v;
				result.distance[neighbour_index] = dist + neighbour_edge;
				Q.addToHeap(Pair<int>(-result.distance[neighbour_index], neighbour_index));
			}		
		}	
	}

	return result;
}
