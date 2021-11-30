#include <iostream>
using namespace std;
int Optor(int i,int j)
{
	cout<<"Return done!"<<endl;
	return i+j;
}

int main()
{
	int receive=Optor(Optor(9,10),Optor(9,10));
	cout<<receive<<endl;
	return 0;
}