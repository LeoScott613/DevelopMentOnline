/*
#include <iostream>
int main()
{
	int x;
	while(scanf("%d",&x))
	{
		printf("%d",x);
	}
	return 0;
}
*/

#include <iostream>
int main()
{
	int a;
	do{
		printf("%d",a);
	}while(scanf("%d",&a));
	return 0;
}
//The difference between do-while and while is do-while always "do" before judging the condition, while while is always judging the condition before "do"