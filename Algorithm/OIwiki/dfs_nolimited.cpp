/**
 * @file dfs.cpp
 * @author your name (you@domain.com)
 * @brief 用dfs方法遍历一颗纯数字树
 * @cite https://oi-wiki.org/search/dfs/
 */
#include <iostream>
using namespace std;
int solution[200];
void dfs(int n) {
    for(int j(1);j<=n;j++) {
        cout<<j<<' ';
        dfs(j-1);
    }
}
int main() {
    int n;
    cin>>n;
    dfs(n);
    return 0;
}