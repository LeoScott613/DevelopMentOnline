#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double bmi,m,h;
	cin>>m>>h;
	bmi=m/pow(h,2);
	if(bmi<18.5)
		cout<<"Underweight"<<endl;
	else if(bmi>=18.5 && bmi<24)
		cout<<"Normal"<<endl;
	else
		cout<<bmi<<endl<<"Overweight"<<endl;
	return 0;
}
