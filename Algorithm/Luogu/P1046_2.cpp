#include <iostream>
int main() {
	int apple[10],h,cnt(0),i;
	for(i=0;i<10;i++)
		std::cin>>apple[i];
	for(std::cin>>h;i>=0;i--)
		cnt+=((h+30)>=apple[i]);
	std::cout<<cnt<<std::endl;
	return 0;
}
