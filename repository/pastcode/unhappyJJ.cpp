/*
#include <iostream>
using namespace std;
int main()
{
	int a[14],i(0),date(0),tim(0),max(8);
	for(;i<=13;i++)
		cin>>a[i];
	for(i=12;i>=0;i-=2)
	{
		tim=a[i]+a[i+1];
		if(tim>max)
		{
			date=i/2+1;
			max=tim-1;
		}
	}
	cout<<date<<endl;
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int unhappy[7], clas, afclas, maxi(0);
	for (int i = 0; i < 7; i++)
	{
		cin >> clas >> afclas;
		unhappy[i] = clas + afclas;
		maxi = max(maxi, unhappy[i]);
	}
	if (maxi <= 8)
		cout << 0;
	else
		for (int i = 0; i < 7; i++)
			if (unhappy[i] == maxi)
			{
				cout << i + 1;
				break;
			}
	return 0;
}