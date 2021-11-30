#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>::iterator itera;
typedef vector<int>::size_type sizt;
typedef vector<int>::difference_type dift;
int bs(int a[], int value, int n) // for array
{
    int low(0), high(n-1), mid(0); // don't have to initialize mid
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == value)
            return mid;
        else if (a[mid] > value)
            high = mid - 1;
        else if (a[mid] < value)
            low = mid + 1;
    }
    return -1;
}
itera bsv(itera a, int value, itera sit)
{ // a=.begin;sit=.end()
    itera error_return = sit;
    sit--;
    itera mid = a + (sit - a) / 2;
    while (a <= sit)
    {
        mid = a + (sit - a) / 2;
        if (*mid == value)
            return mid;
        else if (*mid < value)
            a = mid + 1;
        else if (*mid > value)
            sit = mid - 1;
    }
    return error_return;
}
int main()
{
    int a[] = {0,1,2,3,4,5,6,7,8,9,123,321,432};//a must remain sorted
    //a sorted array or vector can be used in binarysearch
    int which;
    cin >> which;
    int i = bs(a, which, sizeof(a)/4);
    if (i == -1)
        cout << "error" << endl;
    else
        cout << a[i] << endl;

    vector<int> av;
    for (int j = 0; j <= 10; j++)
        av.push_back(j);
    av.push_back(123);
    av.push_back(321);
    av.push_back(432);
    cin >> which;
    itera j = bsv(av.begin(), which, av.end());
    if (j == av.end())
        cout << "failed" << endl;
    else
        cout << *j << endl;

    return 0;
}