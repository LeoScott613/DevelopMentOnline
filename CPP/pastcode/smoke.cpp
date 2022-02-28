#include <iostream>
using namespace std;
int main()
{
	int n,k,overall=0,end(0);
	cin>>n>>k;
	while(n>0){
		n--;
		end++;
		if(end==k){
			n++;
			end=0;
		}
		overall++;
	}
	cout<<overall<<endl;
	return 0;
}
	