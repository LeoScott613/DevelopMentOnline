#include <iostream>
using namespace std;
int main()
{
    // it is about a single value
    int value;
    cin >> value;
    int *p(&value);
    cout << p << endl;
    //cout << *p << endl;

    // it is about an array
    int a[5];
    for (int i(0); i < 5; i++)
        cin >> a[i];
    int *pa = a;//the correct way to initialize the pointer
    for(int j(0);j<5;j++)
    cout<<(pa+j)<<' ';
    return 0;
}