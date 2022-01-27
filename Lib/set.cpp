#include <iostream>
#include <set>
using namespace std;
typedef set<int>::iterator sti;
int main()
{
    int x(10);
    set<int> sb;
    sb.insert(x);
    sti siter(sb.begin());
    cout<<*siter<<endl;
    return 0;
}