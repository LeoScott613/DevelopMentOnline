/*#include <iostream>
int main()
{
	int a(0),b(0);
	std::cin>>a;
	b=a/100+(a%10)*100+(a/10)%10*10;
	std::cout<<b<<std::endl;
	return 1;
}
The Cpp version can't solve the digits problem efficently*/

#include <cstdio>
int main()
{
	int a(0),b(0);
	scanf("%d",&a);
	b=(a%10)*100+((a/10)%10)*10+a/100;
	printf("%03d",b);                   //If I don't add a 0, it will display as " 23".
	return 18;
}
