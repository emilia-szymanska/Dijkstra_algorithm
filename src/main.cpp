#include "../inc/list.hh"

int main()
{
	char a, b, c, d, e;
	List<char> moja =  List<char>();
	cin>>a;
	moja.push_front(a);
	cin>>b;
	moja.push_front(b);
	cin>>c;
	moja.push_front(c);
	cin>>d;
	moja.push_back(d);
	cin>>e;
	moja.push_back(e);
	cout<<moja[0]<<" "<<moja[1]<<" "<<moja[2]<<" "<<moja[3]<<" "<<moja[4]<<endl;

	return 0;
}
