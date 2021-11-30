#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef int setout;
int main()
{
	// while(1){          //test
	double s(0),v(0),result(0);
	cin>>s>>v;
	result=s/v+10;
	result=ceil(result);
	
	int h,min;
	h=result/60;
	min=(int)result%60;
	// cout<<h<<":"<<min<<endl;   //test
	
	//Part2.Solve-----------
	setout hour(0),minute(0);
	if(min==0)
		minute=min;
	else
	{
		minute=60-min;
		hour--;
	}
	
	if(h>=24)
	{
		hour=8;
		minute=0;
	}
	else if(h<24&&h>8)
		hour+=24-(h-8);
	else if(h==8&&hour!=-1)
		hour=0;
	else if(h==8&&hour==-1)
		hour+=24-(h-8);
	else if(h<8)
		hour+=8-h;
	//-----------------------
	
	/*  Part1.Unsolve--------
	if(h>8&&h<24)
		hour=24-(h-8);
	else if(h==8)
		hour=0;
	else if(h<8&&min!=0)
		hour=7-h;
	else if(h<8&&min==0)
		hour=8-h;
	else if(h>=24)
	{
		hour=8;
		min=0;
	}
	
	if(min==0)
		minute=min;
	else
		minute=60-min;
	//------------------------*/
	
	//事实证明什么呢？算术要先从位数小的算起
	
	printf("%02d:%02d",hour,minute);
	// }          //test
	return 0;

}