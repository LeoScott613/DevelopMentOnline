#include <iostream>
using namespace std;
int main() {
    int n;
    int a(1),b(1),c;
    cin>>n;
    for(int i(0);i<2&&i<n;i++)
        cout<<1<<' ';
    for(n-=2;n>0;n--) {
        c=a+b;
        cout<<c<<' ';
        a=b;
        b=c;
    }
    return 0;
    //question 1: why "i<2&&i<n"?
    //question 2: why there are two for loops?
    //question 3: how does it works to output the 1 1?
    //All are vital question.
}