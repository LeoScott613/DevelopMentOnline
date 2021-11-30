#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<int> ivec;
	for(int i=0;i<2;i++)
		ivec.push_back(1);
	vector<int>::size_type ix=0;
	for(;ix<ivec.size();ix++)
		cout<<ivec[ix]<<endl;
	ix=ivec.size();
	cout<<ix<<endl;
	return 0;
}