#include <iostream>

#define max_value 100 

using namespace std;

//argv[1] - ziarno losowosci; argv[2] - gestosc grafu, argv[3] - ilosc wierzcholkow
int main(int argc, char **argv)
{
	if(argc < 4) 
		return 1;
	
	srand(atoi(argv[1]));
	
	int vertex_number = atoi(argv[3]);	
	int max_edges = vertex_number*(vertex_number - 1);
	int edges = (atoi(argv[2])*max_edges)/100;

	cout<<edges<<" "<<vertex_number<<" "<< rand()%vertex_number << endl;

	for (int i = 0; i < edges; i++)
	{
		cout << rand()%vertex_number << " " << rand()%vertex_number << " " << rand()%max_value + 1 <<endl;
		
	}

	return 0;
}
