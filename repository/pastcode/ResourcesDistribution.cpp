#include <iostream>
#include <cmath>
using namespace std;

//I have fixed resource which is described as a number, and I have three functions which take resource and outcome profit.
//How to maximize the profit?
//Always remember, another function must be ahead of main function !!

int obj1(double in1)
{
	return sqrt(log(in1*in1*in1*in1));
}

int obj2(double in2)
{
	return log(sqrt(in2*in2*in2*in2));
}


int main() {
	double res;
	double result = -1, maxi = 0;
	int point = 1;
	cin >> res;
	while(point < res)
	{
		result = obj1(point)+obj2((res-point));
		if (result > maxi) 
			maxi = result;
		point++;
	}
	
	cout<<maxi<<endl;
	
	return 0;
}
