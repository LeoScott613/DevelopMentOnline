#include <iostream>
using namespace std;
int main() {
	int *apples=new int[10];
	for(int i(0);i<10;i++) {
		cin>>apples[i];
	}
	int height(0),counter(0);
	cin>>height;//taotao's height
	for(int i(0);i<10;i++) {
		if(height+30>=apples[i])
			counter++;
	}
	cout<<counter<<endl;
	delete apples;
	apples=NULL;
	return 0;
}
