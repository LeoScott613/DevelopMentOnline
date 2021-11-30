#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
int main()
{
    int v, hposi, leng(10);
    cout << "The velocity of your horse:";
    cin >> v;
    cout << endl;
    cout << "The length of the track:";
    cin >> leng;
    // double timec(leng/v);
    const clock_t delay = (CLOCKS_PER_SEC / v);
    clock_t start;
    for (hposi = 1; hposi <= leng; hposi++)
    {
        system("cls");
        for (int i = 1; i <= leng; i++)
        {
            if (i == hposi)
                cout << 'h';
            else
                cout << '_';
        }
        start = clock();
        while (clock() - start < delay)
            ;
    }
    // cout<<"\nYou spend "<<fixed<<setprecision(3)<<timec<<"s to reach.\n";
    cout<<endl;
    system("pause");
    return 0;
}