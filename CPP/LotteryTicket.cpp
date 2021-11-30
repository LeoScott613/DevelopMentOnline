#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int tick[n][7],award[7],i,j,couter[n]={0};
	for(i=0;i<7;i++)
		cin>>award[i];
	for(i=0;i<n;i++)
		for(j=0;j<7;j++)
			cin>>tick[i][j];        //Input the number by line and row
	int for_store_n=n;              //Cuz later I will use n as a varible
	int &fsn=for_store_n;
	i=n=j=0;
	while(n!=fsn)
	{
		for(i=0;i<7;i++)
			for(j=0;j<7;j++)        //Double for can solve 2-mension array's comparison problem
			{
				if(tick[n][i]==award[j])
					couter[n]++;
			}
		n++; 
	}
	int fine[7]={0};
	for(i=0;i<fsn;i++)
		fine[(couter[i]-1)]++;
	for(i=6;i>=0;i--)
	// for(i=0;i<7;i++)
		cout<<fine[i]<<" ";
	cout<<endl;                        //Refresh the buffer
	return 0;
}
/*Revise: What's the usage of the fine[7] array?
I use this array to store how many ticket get N-level award, 
while the N-level is represented by the index of the fine array*/