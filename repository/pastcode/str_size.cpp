#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;
using std::string::size_type;  //wrong
int main()
{
	string ak("AK47");
	size_type siz=ak.size();
	cout<<siz<<endl;
	return 0;
}