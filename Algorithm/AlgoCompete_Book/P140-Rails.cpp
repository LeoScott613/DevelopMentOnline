#include <iostream>
#include <stack>
using namespace std;
const int MAXN=1000+10;
int main() {
	int *target=new int[MAXN];
	int n;
	stack<int> station;
	while(true) {//the amount of the passage
		cin>>n;
		if(!n)
			break;
		int A,B;
		for(int i(1);i<=n;i++) {
			cin>>target[i];
		}
		bool ok=true;
		A=B=1;    //index varible
		
		while(B<n) {
			if(A==target[B])
				A++,B++;
			else if(!station.empty() && station.top()==target[B]) {
				station.pop();
				B++;
			}
			else if(A<=n)
				station.push(A++);
			else {
				ok=false;
				break;
			}
		}
		//it's the judgement from the book
		
		/*
		while(out<=n) {
			if(target[out]==in)
				in++,out++;
			else if(!station.empty()&&target[out]==station.top()) {
				station.pop();
				out++;
			}
			else 
				station.push(in++);
		}
		fail to complete this version
		*/
		cout<<(ok?"Yes":"No")<<endl;
	}
	return 0;
}
