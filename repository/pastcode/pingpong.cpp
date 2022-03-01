#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
const int ele=11;
const int twe=21;
int i(0),W(0),L(0);
vector<int> overall;
vector<int> statistic;
vector<int>::size_type sizet;
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

int func1(int maxi){
	int j(0);
	// 
	while(1){
		for(j=0;j<maxi&&j+i<sizet;j++){
			if(overall[j+i]==1)
				W++;
			else if(overall[j+i]==0)
				L++;
		}
		i+=maxi;
		if(i>sizet)
			i=sizet-1;
		break;
	}
	return 0;
}

int func2(){
	while(i<sizet){
		if(overall[i]==1)
			W++;
		else if(overall[i]==0)
			L++;
		i++;
		break;
	}
	return 0;
}

int main()
{
	int reci(0);
	while(reci!=-1){
		reci=inpuu();
		overall.push_back(reci);
	}
	sizet=overall.size();
	while(1){
	func1(ele);
	if(i>=overall.size()){
		printf("%d:%d\n",W,L);
		W=L=0;
		break;         
	}
	else if(abs(W-L)>2){
		printf("%d:%d\n",W,L);
		// statistic.push_back(W);
		// statistic.push_back(L);
		W=L=0;
	}
	else{
		while(1){
			func2();
			if(abs(W-L)>2){
				printf("%d:%d\n",W,L);
				// statistic.push_back(W);
				// statistic.push_back(L);
				W=L=0;
				break;
			}
		}
	}
	}//while(1)
	if((i=overall.size())&&(abs(W-L)>2)&&(overall.size()!=0))
		printf("0:0\n");
	cout<<endl;
	/////////21//////////
	i=0;
	while(1)
	{
	func1(twe);
	if(i>=overall.size()){
		printf("%d:%d",W,L);
		W=L=0;
		break;
	}
	else if(abs(W-L)>2){
		printf("%d:%d\n",W,L);
		// statistic.push_back(W);
		// statistic.push_back(L);
		W=L=0;
	}
	else{
		while(1){
			func2();
			if(abs(W-L)>2){
				printf("%d:%d\n",W,L);
				// statistic.push_back(W);
				// statistic.push_back(L);
				W=L=0;
				break;
			}
		}
	}
	}//while(1)
	if((i=overall.size())&&(abs(W-L)>2)&&(overall.size()!=0))
		printf("\n0:0");
	else if(overall.size()==0)
		printf("0:0");
}	