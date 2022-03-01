#include <bits/stdc++.h>
using namespace std;
int main()
{
	double needs,pack[3][2];
	int result[3]={1},i(0),j;
	for(cin>>needs;i<3;i++)
		for(j=0;j<2;j++)
			cin>>pack[i][j];
	for(i=j=0;i<3;i++)
		result[i]=ceil(needs/pack[i][0])*pack[i][1];
	j=min(result[0],min(result[1],result[2]));
	cout<<j<<endl;
	return 0;
}
		