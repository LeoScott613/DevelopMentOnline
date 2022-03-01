#include <cstring>
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
const clock_t delay(10*CLOCKS_PER_SEC);
int main()
{
	int i,j,k,m(1);
	char a[300],b[100],c[100];//开得够大能保证不会溢出
	cout<<"String "<<m<<':',scanf("%s",a);//使用这种方式输入会在结尾自动追加\0
	m++;
	cout<<"String "<<m<<':',scanf("%s",b);
	m++;
	cout<<"String "<<m<<':',scanf("%s",c);
	for(i=0;a[i]!='\0';i++);//i停在a[i]='\0'即“结尾”处
	for(j=0;j<=strlen(b);j++)
		a[i+j]=b[j];//拼接
	for(;a[i]!='\0';i++);//再次停在结尾
	for(k=0;k<=strlen(c);k++)
		a[i+k]=c[k];//拼接
	cout<<"Their combination is "<<'"'<<a<<'"'<<endl;
	clock_t start=clock();
	while(clock()-start<delay);
	return 0;
}
