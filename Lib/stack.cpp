#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(10);
    s.push(9);
    cout<<s.top()<<endl;
    return 0;
}