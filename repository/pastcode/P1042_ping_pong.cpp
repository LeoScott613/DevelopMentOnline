#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
int inpuu()
{
	char c;
	scanf("%c",&c);
	if(c=='W')
		return 1;
	else if(c=='L')
		return 0;
	else if(c=='E')
		return -1;
}
int main()
{
	int i(1),W(0),L(0),reci(-1);
	vector<int> overall;
	vector<int>::size_type sizet=overall.size();
	while(i)
	{
		reci=inpuu();
		if(reci==1)
			overall.push_back(reci);
		else if(reci==0)
			overall.push_back(reci);
		else if(reci==-1) 
			i=0;
	}
	sizet=overall.size();
	int j(0),indi(0);
	for(W=L=0;i<=sizet;i+=11){
		for(j=0;j<11&&j+i<sizet;j++){   //eleven eleven read.
			if(overall[j+i])
				W++;
			else
				L++;
		}
		
		indi=(sizet-i)/11;
		if(indi&&abs(W-L)>2&&W+L>=11)
		{	printf("%d:%d\n",W,L);W=L=0;}
		if(indi==0)
		{	printf("%d:%d\n",W,L);W=L=0;}
	}
	cout<<endl;
	for(W=L=i=0;i<=sizet;i+=21){
		for(j=0;j<21&&j+i<sizet;j++){
			if(overall[j+i])
				W++;
			else 
				L++;
		}
		
		indi=(sizet-i)/21;
		if(indi&&abs(W-L)>2&&W+L>=21)
		{	printf("%d:%d\n",W,L);W=L=0;}
		if(indi==0)
		{	printf("%d:%d",W,L);W=L=0;}
	}
	return 0;
}
