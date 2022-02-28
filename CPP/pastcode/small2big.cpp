#include <iostream>
using namespace std;
int main()
{
	int a[3],i(0);
	for(;i<3;i++)
		cin>>a[i];
	int temp(0);
	for(int j(0);j<3;j++)
		for(i=2;i>0;i--)
			if(a[i]<a[i-1])
			{
				temp=a[i-1];
				a[i-1]=a[i];
				a[i]=temp;
			}//better swap();
	for(i=0;i<3;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}