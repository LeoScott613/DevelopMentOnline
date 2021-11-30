#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    cin >> t;//个数
    const int tt = t;//个数即行数
    string ans;
    double data[tt][4];//每行4个数据,double !
    for (int i(0); i < t; i++)
        for (int j(0); j < 4; j++)
            cin >> data[i][j];
    //a1/b1是5s的性价比
    //a1是data[i][0],b1是data[i][1]
    //a2 data[i][2],b2 data[i][3]
    for (int i(0); i < t; i++)
    {
        if ((data[i][2] / data[i][3]) > (data[i][0] / data[i][1]))
            ans += "iphone 5C";
        else
            ans += "iphone 5S";
        if(i!=t-1)
            ans+='\n';
    }
    cout<<ans;
    return 0;
}