#include <iostream>
#include <iomanip>
#include <cmath>
int main()
{
	double m,t,s,last;
	std::cin>>m>>t>>s;
	if(t==0)
		std::cout<<0<<std::endl;
	else
	{
		last=m-s/t;
		if(last<0)
			last=0;
		// std::cout<<std::fixed<<std::setprecision(0)<<floor(last)<<std::endl;
		std::cout<<floor(last)<<std::endl;
		/*Points: fixed, setprecision is in the std namespace*/
		/*Points:setprecision(0) will make it use scientific counting method to display the last, std::fixed can fix that.*/
	}
	return 0;
}
