/**
 * @file catalan.cpp
 * @author Leo Scott
 * @brief 由于随机出入栈满足卡特兰数列，所以直接用计算卡特兰数列的程序可以解决
 * @date 2022-05-07
 * @cite https://www.luogu.com.cn/problem/P1044
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