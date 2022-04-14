#include <iostream>
using namespace std;
int main() {
    int x,n;
    cin>>x>>n;
    bool weekday[7]={true,true,true,true,true,false,false};
    bool *p=weekday+x-1;
    long distance(0);//the scale of the data has been considered.
    for(;n>0;n--) {
        if(*p==true)
            distance+=250;
        p++;
        if(p==weekday+7)
            p=weekday;
    }
    cout<<distance<<endl;
    return 0;
}