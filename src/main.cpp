#include "../inc/list.hh"
//#include "../inc/GraphList.hh"
#include "../inc/GraphMatrix.hh"

int main()
{
	GraphMatrix grafik = GraphMatrix(5);
	grafik.insertEdge(0, 1, 3);
	grafik.insertEdge(0, 4, 1);
	grafik.insertEdge(1, 4, 1);
	grafik.insertEdge(1, 3, 2);
	grafik.insertEdge(2, 2, 1);
	grafik.insertEdge(4, 3, 2);
	cout<<grafik.Size()<<endl;
	cout<<grafik.areAdjacent(0, 1)<<" "<<grafik.areAdjacent(1, 2)<<" "<<grafik.areAdjacent(3, 4)<<" "<<grafik.areAdjacent(4, 3)<<" "<<endl;

	/*List<Pair<int> > meh = grafik.incidentEdges(0);
	for(int i = 0; i < meh.size(); i++) 
	{
		cout<<meh.front().first<<" "<<meh.front().second<<" ";
		meh.pop_front();
	}*/
	return 0;
}
