#include <iostream>
using namespace std;
int main()
{
	int weigh,a;
	cin>>weigh;
	a=weigh%2;
	if(a||weigh==2)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;
	return 0;
}