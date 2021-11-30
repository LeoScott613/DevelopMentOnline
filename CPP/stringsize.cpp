#include <iostream>
#include <string>
//using namespace std::string;   <- wrong, cuz std is a namespace but std::string is not a namespace. "namespace"should be deleted.
//String is a stl, not a basic type. Should use #include
using namespace std;
int main() 
{
	string st("Date back to 1999");
	cout<<st.size()<<endl;
	return 0;
}
