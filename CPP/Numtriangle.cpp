#include <iostream>

int main(int argc, char** argv) 
{
	int po=1,line=0,i=1,exe=1;
	std::cin>>line;
	while(line>=1)
	{
		for(;po<=line;po++&&exe++)
		{
			if(exe<10) std::cout<<"0"<<exe;
			else std::cout<<exe;
		}
		po=1;
		std::cout<<std::endl;
		line--;
	}

	return 0;
}
