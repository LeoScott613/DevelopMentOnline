#include <iostream>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int main()
{
	int n,sum(0);
	cin>>n;
	forr(i,1,n)
		sum+=i;
	cout<<sum<<endl;
	return 0;
}
	