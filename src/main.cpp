#include "../inc/list.hh"
//#include "../inc/GraphList.hh"
//#include "../inc/GraphMatrix.hh"
#include "GraphList.cpp"
#include "GraphMatrix.cpp"
#include "../inc/Dijkstra.hh"
#include <ctime>
#include <iomanip>

int main()
{
	double timing;
	
	int edge, vertex, start, v1, v2, value;
	
	cin>>edge>>vertex>>start;
	//GraphList grafik = GraphList(vertex);
	GraphMatrix grafik = GraphMatrix(vertex);
	
	for(int i = 0; i < edge; i++)
	{
		cin>>v1>>v2>>value;
		grafik.insertEdge(v1, v2, value);
	}
	
	clock_t begin = clock();

	Dijkstra_results wynik = dijkstra_algorithm(grafik, start);	
	
	clock_t end = clock();
	
	timing = (end - begin)/((double)CLOCKS_PER_SEC/1000);

	cout << fixed << setprecision(5) << timing << endl;	

	/*for(int i = 0; i < 5; i++)
	{
		cout<<wynik.distance[i]<<" "<<wynik.previous[i]<<endl;
	}*/

	return 0;
}
