#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a, b, c;
    int t;
    cin >> t;
    const int tt(t);
    double ans[tt];
    for (int i(0); i < t; i++)
    {
        cin >> a >> b >> c;
        ans[i] = 0.25 * a + 0.25 * b - 0.5 * c;
    }
    for (int i(0); i < t; i++)
        cout << fixed << setprecision(6) << ans[i] << endl;
    return 0;
}