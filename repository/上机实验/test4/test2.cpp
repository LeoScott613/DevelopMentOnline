#include <iostream>
using namespace std;
int a[4][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
int main()
{
    int *p1(&(a[0][0])), **p2(&p1), *p3[5], *p4[4];
    for (int i(0); i < 5; i++)
        p3[i] = &a[0][i];
    for (int i(0); i < 4; i++)
        p4[i] = &a[i][0];
    for (int i(0); i < 20; i++)
    {
        cout<<"p1->:"<<*(p1+i)<<' ';
        cout<<"p2->:"<<*(*p2+i)<<' ';
        cout<<"p3->:"<<*(p3[0]+i)<<' ';
        cout<<"p4->:"<<*(p4[0]+i)<<' '<<endl;
    }
    return 0;
}