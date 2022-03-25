#include <stack>
#include <iostream>
using namespace std;
int main() {
    stack<int> origin,sup;
    int x(0);
    cin>>x;
    while(x) {
        if(origin.empty())
            origin.push(x);
        else {
            while(!origin.empty()&&origin.top()<x) {
                sup.push(origin.top());
                origin.pop();
            }
            origin.push(x);
            while(!sup.empty()) {
                origin.push(sup.top());
                sup.pop();
            }
        }
        cin>>x;
    }
    while(!origin.empty()) {
        cout<<origin.top()<<' ';
        origin.pop();
    }
    return 0;
}