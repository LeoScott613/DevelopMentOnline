#include <iostream>
using namespace std;
int main()
{
	int nowcoin(1), allup(0), i, k;
	cin >> k;
	for (i = 1; k > 0; i++)
	{
		k--;
		allup += nowcoin;
		if (i == nowcoin)
		{
			nowcoin++;
			i = 0;
		}
	}
	cout << allup << endl;
	return 0;
}
