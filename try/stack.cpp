#include <stack>
#include <iostream>
using namespace std;
int main() {
    stack<int> sdek;
    for(int i(0);i<10;i++) {
        sdek.push(i+1);
    }
    while(!sdek.empty()) {
        cout<<sdek.top()<<endl;
        sdek.pop();
    }
    return 0;
}