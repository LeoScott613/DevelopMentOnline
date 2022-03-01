#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;
const clock_t delay(10 * CLOCKS_PER_SEC);
int main()
{
	int a[4][6]; // definition
	for (int i(0); i < 4; i++)
		for (int j(0); j < 6; j++)
			cin >> a[i][j]; // input
	for (int i(0); i < 4; i++)
	{
		int muti(1);
		for (int j(0); j < 6; j++)
		{
			muti *= a[i][j];
			if (a[i][j] == 0)
			{ //防止0出现
				muti = 0;
				break;
			}
		}
		cout << "line " << i + 1 << ':' << muti << endl; // put out every time
	}
	unsigned long long muti_all = 1; //因为整个数组的乘积等于所有列的乘积的乘积，因此每次列乘积的结果都在overall中累乘就可以算出来所有数的乘积了
	for (int i(0); i < 6; i++)
	{
		int muti(1);
		for (int j(0); j < 4; j++)
		{
			muti *= a[j][i];
			if (a[j][i] == 0)
			{
				muti = 0;
				break;
			}
		}
		muti_all *= muti;
		cout << "column " << i + 1 << ':' << muti << endl;
	}

	for (int i(0); i < 4; i++) //打印整个数组
	{
		for (int j(0); j < 6; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	cout << "overall mutiply:" << muti_all << endl;
	clock_t start = clock();
	while (clock() - start < delay)
		;//循环等待观察结果
	return 0;
}