template <class T>
Dijkstra_results dijkstra_algorithm(T graph, int vertex)
{
	int v, dist, neighbour_index, neighbour_edge;
	unsigned int number_of_elements = graph.Size();
	int * prev = new int [number_of_elements];			//table - previous vertex 
	int * d = new int [number_of_elements];				//table - best distance
	for(unsigned int i = 0; i < number_of_elements; i++)		// making ,,infinity'' values
	{	
		d[i] = -1;
		prev[i] = -1;
	}

	d[vertex] = 0;
	Heap<Pair<int> > Q = Heap<Pair<int> >(0);	
	Q.addToHeap(Pair<int>(0, vertex));
	while(!Q.isEmpty())						//Dijkstra's magic
	{
		dist = -Q.seeRoot().first;
		v = Q.seeRoot().second;
		cout<<"cos"<<endl;				//!!!!
		Q.takeFromHeap();
		if(dist > d[v]) continue;
		List<Pair<int> > neighbours = graph.incidentEdges(v);
		for (auto It = neighbours.begin(); It != neighbours.end(); It++)
		{
			
			neighbour_index = (*It).first;
			neighbour_edge = (*It).second;
			if(d[neighbour_index] == -1 || d[neighbour_index] > dist + neighbour_edge)
			{       	
				prev[neighbour_index] = v;
				d[neighbour_index] = dist + neighbour_edge;
				Q.addToHeap(Pair<int>(-d[neighbour_index], neighbour_index));
			}		
		}	
	}

	Dijkstra_results result = Dijkstra_results(number_of_elements);			//putting results into special struct
	for(unsigned int i = 0; i < number_of_elements; i++)
	{
		result.distance[i] = d[i];
		result.previous[i] = prev[i];
	}
	
	delete [] d;
	delete [] prev; 

	return result;
}
