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
	moja.push_front(d);
	cin>>e;
	moja.push_front(e);
	for(auto it = moja.begin(); it != moja.end(); it++) cout<<*it<<" ";
	cout<<endl;
	return 0;
}
