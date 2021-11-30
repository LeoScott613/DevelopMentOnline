#include <iostream>
#include <algorithm>
// #define _for(i,a,b) for(int i=(a);i<(b);i++);
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a[n], mini, i(0);
	do
	{
		cin >> a[i];
		i++;
	} while (i < n);
	mini = a[i - 1]; // after the last one time do-while, i=n, and a[n] means nothing
	for (i = 0; i < n; i++)
	{
		mini = min(a[i], mini);
	}
	cout << mini << endl;
	return 0;
}
