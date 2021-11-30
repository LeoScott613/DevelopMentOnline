#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int ln[t][2],i,j,a,b,max[t]={0};   //int array[行][列]
	for(i=0;i<t;i++)
		for(j=0;j<2;j++)
			cin>>ln[i][j];
	for(i=0;i<t;i++)
	{
		for(b=ln[i][1];b>ln[i][0];b--)
		{
			for(a=b-1;a>ln[i][0];a--)  
			{
				if(max[i]<b%a)
					max[i]=b%a;
				if(a<=max[i])
				{
					break;
					j=0;
				}
			}
			if(j==0)
				break;
		}
	}
	for(i=0;i<t;i++)
		cout<<max[i]<<endl;
	return 0;
}
