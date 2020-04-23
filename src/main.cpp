#include "../inc/stack.hh"
#include "../inc/list.hh"
#include "GraphList.cpp"
#include "GraphMatrix.cpp"
#include "../inc/Dijkstra.hh"
#include <ctime>
#include <iomanip>

int main()
{
	int vertex, edge, start, v1, v2, value;
	
	cin>>edge>>vertex>>start;
	
	//GraphList grafik = GraphList(vertex);
	GraphMatrix grafik = GraphMatrix(vertex);

	for(int i = 0; i < edge; i++)
	{
		cin>>v1>>v2>>value;
		grafik.insertEdge(v1, v2, value);
	}
	
	Dijkstra_results wynik = dijkstra_algorithm(grafik, start);	
	
	int how_many;
	Stack<int> stosik = Stack<int>(vertex);
	for(int i = 0; i < vertex; i++)
	{
		cout << "Wierzcholek " << i << endl;
		cout << "   koszt " << wynik.distance[i] << endl;
		how_many = 0;
		for(int j = i; j != -1; j = wynik.previous[j])
		{
			stosik.push(j);
			how_many++;
		}	
		
		cout << "   sciezka ";

		while(how_many--)
		{
			cout << stosik.top() << " ";
			stosik.pop();
		}
		cout << endl;	

	}
	return 0;
}
