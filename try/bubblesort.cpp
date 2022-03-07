#include <iostream>
using namespace std;
const int mn(100);
int main(){
    int sor[mn];
    int i;
    for(int x;i<mn;i++){
        cin>>x;
        if(x==0)
            break;
        sor[i]=x;
    }
    i--;
    for(int j(i);j>=0;j--)
        for(int k(0);k<j;k++){
            if(sor[k]>sor[k+1])
                swap(sor[k],sor[k+1]);
        }
    for(int j(0);j<=i;j++)
        cout<<sor[j]<<' ';
    cout<<endl;
    return 0;
}