#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    const int nn = n;
    int nums[nn];
    int i(0);
    for (i = 0; i < nn; i++)
        cin >> nums[i];
    int lef(0), righ(0), wa(0);
    for (i = 0; nums[i] < nums[i + 1]; i++)
        ; // record the position
    righ = nums[i];
    bool po = false;
    for (; i < nn; i++)
    {
        if (nums[i] < righ && !po)
        {
            po = true;
            righ = nums[i];
            continue;
        }
        if (nums[i] > righ && po)
        {
            wa++;
            po = false;
            righ = nums[i];
        }
        else
            righ = nums[i];
    }
    cout << wa << endl;
    return 0;
}