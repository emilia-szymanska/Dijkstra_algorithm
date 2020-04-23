#include "../inc/list.hh"
//#include "../inc/GraphList.hh"
//#include "../inc/GraphMatrix.hh"
#include "GraphList.cpp"
#include "GraphMatrix.cpp"
#include "../inc/Dijkstra.hh"
#include <ctime>
#include <iomanip>

#define max_value 100


//argv[1] - ziarno losowosci, argv[2] - gestosc grafu, argv[3] - ilosc wierzcholkow
int main(int argc, char**argv)
{
	if(argc < 4) 
		return 1;
	
	srand(atoi(argv[1]));
	
	int vertex = atoi(argv[3]);	
	int max_edges = vertex*(vertex - 1);
	int edge = (atoi(argv[2])*max_edges)/100;
	int start = rand()%vertex;

	double timing;
	
	//GraphList grafik = GraphList(vertex);
	GraphMatrix grafik = GraphMatrix(vertex);
	
	for(int i = 0; i < edge; i++)
	{
		grafik.insertEdge(rand()%vertex, rand()%vertex, rand()%max_value + 1);
	}
	
	clock_t begin = clock();

	Dijkstra_results wynik = dijkstra_algorithm(grafik, start);	
	
	clock_t end = clock();
	
	timing = (end - begin)/((double)CLOCKS_PER_SEC/1000);

	cout << fixed << setprecision(5) << timing << endl;	

	/*for(int i = 0; i < vertex; i++)
	{
		cout<<wynik.distance[i]<<" "<<wynik.previous[i]<<endl;
	}*/

	return 0;
}
