/*This programme represent that I can use both C/C++ language in one source file*/
#include <stdio.h>
#include <math.h>
int main()
{
	const double pii=acos(-1.0);                  //acos means arccos
	double r(0),h(0);
	scanf("%lf%lf",&r,&h);
	printf("%.3lf",2*pii*pow(r,2)+2*pii*r*h);     //Don't use power(),use it for short pow()
	return 0;
}