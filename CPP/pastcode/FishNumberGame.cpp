#include <iostream>
int main()
{
	int numb[100],i(0);
	for(std::cin>>numb[i];numb[i]!=0;i++)
		std::cin>>numb[i+1];                //it is couterintuition.I must understand the workflow of "for".
	for(i--;i>=0;i--)
		std::cout<<numb[i]<<" ";
	std::cout<<std::endl;
	return 0;
}
//Unsolved