bool GraphList::areAdjacent(int v, int w)
{
	for(auto it = this->V[v].begin(); it != this->V[v].end(); it++) 
		if ((*it).first == w) return true;  		
	return false;
}


void GraphList::insertEdge(int v, int w, int o)
{
	Pair<int> new_pair = Pair<int>(w, o);
	this->V[v].push_back(new_pair);
	return;
}
		
List<Pair<int> > & GraphList::incidentEdges(int v)
{
	return V[v];	
}
		
