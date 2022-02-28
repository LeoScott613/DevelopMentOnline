#include <iostream>
using namespace std;
int main()
{
    int a(100),b(a<<1),c(a>>1),d(a<<2),e(a>>2);
    cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<' '<<endl;
    return 0;
}