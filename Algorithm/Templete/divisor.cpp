#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int num;
    cin >> num;
    int destin(sqrt(num));
    bool divisor(true);
    for (int i(2); i <= destin; i++)
        if (!(num % i))
        {
            divisor = false;
            break;
        }
    if (divisor)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}