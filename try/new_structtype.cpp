#include <iostream>
using namespace std;
typedef struct fet {
    int data;
    struct fetd *p;
}fet,*fetch;
void newlist(fet *p) {
    p=new fet;
    p->p=NULL;
}
int main() {
    fet *p;
    newlist(p);
    for(int i(0);i<29000;i++) {}
    p->data=1;
    cout<<p->data;
    return 0;
}