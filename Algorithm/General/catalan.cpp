/**
 * @file catalan.cpp
 * @author Leo Scott
 * @brief 计算第n个卡特兰数，此处的卡特兰数从第0项开始。第0项为1
 * @date 2022-05-07
 */
#include <iostream>
using namespace std;
/**
 * @param n 
 * @return the n th catalan number 
 */
long catalan(int n) {
    if(n<2)
        return 1;
    else {
        long retur(0);
        for(int i(n);i>0;i--)
            retur+=catalan(n-i)*catalan(i-1);
        return retur;
    }
}
int main() {
    int n;
    cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}