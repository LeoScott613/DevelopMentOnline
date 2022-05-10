/**
 * @file catalan_short.cpp
 * @author Leo Scott
 * @brief 用递推的方式，将数列放在数组中，而不用递归+备忘录的方式
 */
#include <iostream>
using namespace std;
int n,catalan[50]={0};
int main() {
    cin>>n;
    catalan[0]=catalan[1]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<i;j++)
            catalan[i]+=catalan[j]*catalan[i-j-1];
    cout<<catalan[n]<<endl;
    return 0;
}