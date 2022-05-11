/**
 * @file dfs.cpp
 * @author your name (you@domain.com)
 * @brief 这是例题的记录
 * @cite https://oi-wiki.org/search/dfs/
 */
#include <iostream>
using namespace std;
int arr[100],m;
void dfs(int n, int i, int a) {
    if(n==0) {
        for(int j(1);j<i;j++)
            cout<<arr[j]<<' ';
        cout<<endl;
    }
    if (i <= m) {
        for (int j = a; j <= n; ++j) {
            arr[i] = j;
            dfs(n - j, i + 1, j);  // 请仔细思考该行含义。
        }
    }
}
int main() {
    int n;
    cin>>n>>m;
    dfs(n,1,1);//why n,1,1
    //proved: dfs(n,1,0);
    return 0;
}