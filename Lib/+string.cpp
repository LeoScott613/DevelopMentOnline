#include <string>
#include <iostream>
using namespace std;
int main()
{
    string appen,head;
    appen="Hello";
    head="World";
    string p,n;
    p=appen+head;
    n=head+appen;
    cout<<p<<endl;
    cout<<n<<endl;
    return 0;
}