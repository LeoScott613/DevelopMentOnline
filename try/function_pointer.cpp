#include <iostream>
typedef int (*po)(int,int);
using namespace std;
int add(int x,int y)
{
	return x+y;
}
int main()
{
	po abc=add;
	std::cout<<abc(3,4)<<std::endl;
	return 0;
}
