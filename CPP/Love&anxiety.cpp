#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	const int nn(n);
	int a[nn]={0},i,j,mini,sumup(0);
	for(i=0;i<n;i++)
		cin>>a[i];
	for(j=0;j<m;j++)
		sumup+=a[0+j];
	mini=sumup;
	for(i=0;i<n-m;i++){
		for(j=0;j<m;j++)
			sumup+=a[i+j];
		mini=min(mini,sumup);
		sumup=0;
	}
	cout<<mini<<endl;
	return 0;
}