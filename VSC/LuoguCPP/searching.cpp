#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>::iterator itera;
typedef vector<int>::difference_type dift;
itera bsv(itera low, int value, itera high)
{
    itera error_return = high, mid;
    high--;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (*mid == value)
        {
            while (*mid == value)
                mid--; // the extra step is promising that it will return the most advanced iterator
            return ++mid;
        }
        else if (*mid < value)
            low = mid + 1;
        else if (*mid > value)
            high = mid - 1;
    }
    return error_return;
}
int pb()
{
    int x;
    cin >> x;
    return x;
}
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> numbers;
    const int mm = m;
    int *request = new int[m];
    for (int i = 0; i < n; i++)
        numbers.push_back(pb());
    for (int i = 0; i < m; i++)
        cin >> request[i];
    itera i;
    dift nob;
    for (int j = 0; j < m; j++)
    {
        i = bsv(numbers.begin(), request[j], numbers.end());
        nob = (i - numbers.begin()) + 1;
        if (i == numbers.end())
            cout << -1 << ' ';
        else
            cout << nob << ' ';
    }
    delete[] request;
    return 0;
}
