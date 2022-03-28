#include <iostream>
using namespace std;
int main() {
    void *general;
    int *pp,num(47);
    pp=&num;
    general=pp;
    cout<<*((int*)general)<<endl;
    return 0;
}