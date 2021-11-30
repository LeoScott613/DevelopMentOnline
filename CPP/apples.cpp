#include <iostream>
using namespace std;
int main()
{
	int apples(0);
	cin>>apples;
	if(apples<=1)
		cout<<"Today, I ate "<<apples<<" apple."<<endl;
	else 
		cout<<"Today, I ate "<<apples<<" apples."<<endl;
	return 0;
}