/*
I create a loop to calculate the number of inversions before specific fish and then the next fish. 
Everu time I solve out the number of inversions before a specific fish I store it in a varible,
and I will output the varible then clear it, ready for the next fish.
*/
#include <iostream>
int main()
{
	int n,couter;
	std::cin>>n;
	int fish[n];
	for(int i=0;i<=n-1;i++)
		std::cin>>fish[i];
	std::cout<<"0 ";
	for(int i=1;i<=n-1;i++)          //The fish I am pointing at is fish[i];
	{
		for(int j(0);j<i;j++)    //The fish the fish[i] is pointing at is fish[j]
			if(fish[j]<fish[i])  //fish[n] reflects the cute mark;
				couter++;
		std::cout<<couter<<" ";
		couter=0;         
	}
	std::cout<<std::endl;
	return 0;
}