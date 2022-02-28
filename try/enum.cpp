#include <iostream>
using namespace std;
int main()
{
    enum {one=1,two,three} numb;
    numb=one;
    cout<<numb<<endl;
    return 0;
}