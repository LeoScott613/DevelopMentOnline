#include <iostream>
int main()
{
	int x(8);
	printf("%d\n",scanf("%d",&x));
	std::cout<<x<<std::endl;
	return 0;
}
//scanf函数有三种返回值，-1,0,1
//当scanf返回-1时代表着输入错误，包括从输入流中读取到了EOF，返回1时代表着进行了正确的输入，返回0时代表着进行了错误的输入