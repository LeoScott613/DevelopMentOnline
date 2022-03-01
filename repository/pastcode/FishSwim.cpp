#include <iostream>

int main(int argc, char** argv) {
	int a,b,c,d,e,f;
	std::cin>>a>>b>>c>>d;
	if (d < b)
	{
		d += 60;
		c -= 1;
	}
	e = c - a;
	f = d - b;
	std::cout<<e<<" "<<f<<std::endl;
	return 0;
}
