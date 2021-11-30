#include <iostream>
//#include <sstream>
#include <string>
using namespace std;
int num(2),sum(0);
const string line="1+2+3+4+5+6+7+8+9+10+11+12+13+14+15+16+17+18+19+20+21+22+23+24+25+26+27+28+29+30";
string::const_iterator where=line.begin()+2;
int recursion()
{
	sum+=num;
	string::const_iterator bl=line.begin();
	for(;bl<=where;bl++)
	cout<<*bl;
	cout<<'='<<sum<<endl;
	where+=2;
	if(num<30)
	{
	num++;
	return recursion();
	}
}

int main()
{
	recursion();
	return 0;
}	
