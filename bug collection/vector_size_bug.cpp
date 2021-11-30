#include <iostream> 
#include <vector>
using namespace std;
char inpuu()
{
	char c;
	scanf("%c",&c);
	return c;
}
int main()
{
	vector<char> points;
	vector<int>::size_type sizet=points.size();
	int temp(0);
	for(;temp<11;temp++)
		points.push_back(inpuu());
	int i(0),W(0),L(0);
	while(i<sizet){
		if(points[i]=='W')
			W++;
		else if(points[i]=='L')
			L++;
		
		if(W+L==11){
			printf("%d:%d",W,L);
			W=L=0;
		}
	}
}

/*Bug: get points.size() before pushback any number, so sizet will always keep 0!*/