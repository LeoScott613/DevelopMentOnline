#include <iostream>
#include <string>
using namespace std;
int main()
{
	const string lo="Local";
	const string luo="Luogu";
	int num(0),res1(num),res2(num);
	cin>>num;
	res1=num*5;
	res2=num*3+11;
	if (res1<res2)
		cout<<lo<<endl;
	else 
		cout<<luo<<endl;
	return 0;
}
