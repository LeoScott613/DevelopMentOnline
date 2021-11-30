// #include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	double one(0),rev(0);
	cin>>one;
	int oth=one*10;          //I used to make oth as an double, but it cause error;Cuz I can't % an float number
	rev=((oth%10)*1000+(oth/10)%10*100+(oth/100)%10*10+oth/1000);
	rev/=1000;
	cout<<rev<<endl;
	return 0;
}