#include<iostream>
#include<cmath>
#include<stdio.h>

using namespace std;

int main()
{
	double s,v;
	cin>>s>>v;
	double addup;
	addup=ceil(s/v+10);
	
	int timeset[25],i(0),j(8);
	for(;i<=8;i++){
		timeset[i]=j;
		j--;
	}
	for(j=23;i<25;i++){
		timeset[i]=j;
		j--;
	}
	i=floor(addup/60);   
	if(i>23)
		i=23;
	int min;
	if(( (int)addup%60 )==0 || addup>=1440)
		min=0;
	else{
		min=60-( (int)addup%60 );
		i++;
	}
	printf("%02d:%02d",timeset[i],min);
	return 0;
}