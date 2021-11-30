#include <iostream>
using namespace std;
int main()
{
    int a(0b00000011),buma(0b11111110),c(a&buma);
    cout<<c<<endl;
    return 0;
}