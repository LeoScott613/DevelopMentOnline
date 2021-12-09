#include <iostream>
#include <cstring>
using namespace std;
int a[3][4][5], i(1);
int main()
{
    memset(a, 0, sizeof(a));
    for (int *p(&a[0][0][0]); p != &a[3][4][5]; p++)
    {
        *p = i;
        i++;
    }
    int *p1(&a[0][0][0]), **p2(&p1), *p3[5] = {(&a[0][0][0])}, *p4[4] = {(&a[0][0][0])};
    for (i = 0; i < 3 * 4 * 5; i++)
    {
        cout << "p1->:" << *(p1 + i) << ' ';
        cout << "p2->:" << *(*p2 + i) << ' ';
        cout << "p3->:" << *(p3[0] + i) << ' ';
        cout << "p4->:" << *(p4[0] + i) << ' ' << endl;
    }
    return 0;
}