#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
const clock_t delay(CLOCKS_PER_SEC);
clock_t start;
int main()
{
    ios::sync_with_stdio(false);
    int i, j;
    bool value(0);
    while (1)
    {
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
                cout << value << ' ';
            cout << endl;
        }
        start = clock();//the clock when start to delay
        while (clock() - start <= delay)//ask for clock every time and judge if it's more than 1second
            ;
        system("cls");
        value = !value;
    }
    return 0;
}