#include <iostream>
#include <iomanip>
// using namespace std;
int main()
{
	double a,b,c,average;
	std::cin>>a>>b>>c;
	average=(a+b+c)/3;
	std::cout<<std::fixed<<std::setprecision(3)<<average<<std::endl;
	return 0;
}
	