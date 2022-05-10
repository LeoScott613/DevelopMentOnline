#include <iostream>
#include <map>
using namespace std;
map<int,long> note;
long cata(int n) {
    if(n<2) {
        return 1;
    }
    else {
        long reply(0);
        for(int i(n);i>0;i++) {
            reply+=cata(n-i)*cata(i-1);
        }
        return reply;
    }
}
int main() {
    int n;
    cin>>n;
    cout<<cata(n)<<endl;
    return 0;
}