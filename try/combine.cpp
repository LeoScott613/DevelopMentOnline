#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    int a[3]={1,2,3},b[3]={4,5,6},merge[6],j(0),k(0);
    for(int i(0);i<6;i++) {//problem: if j run after a, a[j] is meaningless
        if(k>=3)
            merge[i]=a[j++];
        else if(j>=3)
            merge[i]=b[k++];

        else if(a[j]<=b[k])
            merge[i]=a[j++];
        else if(b[k]<a[j])
            merge[i]=b[k++];
    }
    for(int i(0);i<6;i++)
        cout<<merge[i]<<' ';
    return 0;
}