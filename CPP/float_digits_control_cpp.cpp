#include <iostream>
#include <cmath>                //not where the setprision method in
#include <iomanip>              //it is
using namespace std;
int main()
{
	const double pii=acos(-1);
	cout<<pii<<endl;
	cout<<setprecision(1)<<pii<<endl;       //setprecision is in std namespace
	cout<<setprecision(2)<<pii<<endl;
	cout<<setprecision(3)<<pii<<endl;
	cout<<pii<<endl;
	cout<<fixed<<setprecision(1)<<pii<<endl;
	cout<<fixed<<setprecision(0)<<floor(pii)<<endl;
	cout<<ceil(pii)<<endl;
	return 0;
}