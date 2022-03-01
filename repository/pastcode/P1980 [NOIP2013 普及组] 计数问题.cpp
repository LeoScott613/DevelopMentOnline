#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main()
{
	vector<int> incl;
	incl.push_back(0);
	int start,i,x;
	cin>>start>>x;
	for(i=1;i<=start;i++)
		incl.push_back(i);
	ofstream fileop("P1980.lhx");
	ifstream fileop2("P1980.lhx");
	vector<int>::size_type sizetype=incl.size();
	for(i=0;i<sizetype;i++)
		fileop<<incl[i];
	vector<char> chacl;
	int filelen=fileop2.gcount();
	chacl.push_back((char)(fileop2.read(filelen,sizeof(filelen))));
	vector<char>::size_type chsiz=chacl.size();
	int count(0);
	for(i=0;i<chsiz;i++)
		if(chacl[i]==x)
			count++;
	cout<<count<<endl;
	return 0;
}
	
