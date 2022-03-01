#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
	double a,b,c;
	double area,p;
	cin>>a>>b>>c;
	p=(a+b+c)/2;
	area=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.1lf",area);
	
	return 0;
}