#include <iostream>
#include <cstdio>//scanf所在的头文件
#include <cstring>//strlen函数所在的头文件
#include <algorithm>//swap函数所在的头文件
#include <ctime>
using namespace std;
const clock_t delay(10*CLOCKS_PER_SEC);
int main()
{
	char a[200];
	scanf("%s", a);//使用%s占位符对a进行输入，此处a为指针，字符串会依次从a数组开头的地址填入数组a
	int len = strlen(a);//获取纯粹的字符串长度，不包括\0
	for (len--; len >= 0; len--)//Bubble sort
		for (int j = 0; j < len; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	cout <<"Sorted :"<<a << endl;//output
	const clock_t start=clock();
	while(clock()-start<delay);
	return 0;
}
