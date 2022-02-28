#include <iostream>
#include <string>
#include <ctime>
using namespace std;
const clock_t delay(10*CLOCKS_PER_SEC);
typedef string::iterator sti;//缩短定义一个迭代器所需的代码量
string ori,sign,replas;//分别对应题目的串123
int main()
{
	cin>>ori>>sign>>replas;
	string bottle,cup;//用于存放分割后的左右字符串
	sti sigbg=sign.begin();
	for(sti i=ori.begin();i<=ori.end()-sign.size();i++)
	{
		if(*i==*sigbg)//检测到有一个匹配的就开始将后面几个都装入compare准备与sign比较
		{
			string compare;
			for(int j=0;j<sign.size();j++)
				compare+=*(i+j);
			if(compare==sign)
			{
				for(sti bot=ori.begin();bot<i;bot++)//从原始字符串开头到i
					bottle+=*bot;
				i+=sign.size();
				for(sti cp=i;cp!=ori.end();cp++)//从被替换的串到结尾
					cup+=*cp;
				ori=bottle+replas+cup;
				i=ori.begin()+bottle.size();//经过上一个操作后迭代器失效
				bottle.clear();//重置，准备给下一次使用
				cup.clear();
			}
		}
	}
	cout<<ori<<endl;
	clock_t start=clock();
	while(clock()-start<delay);
	return 0;
}
			
				
