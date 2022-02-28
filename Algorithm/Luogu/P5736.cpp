/*P5736 【深基7.例2】质数筛*/
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
bool buk[100000];
int main()
{
    memset(buk, false, sizeof(buk));
    bool ij(true);
    for (int i(2); i < 99997; i++)
    {
        ij = true;
        for (int j(2); j <= sqrt(i); j++)
            if (!(i % j))
            {
                ij = false;
                break;
            }
        if (ij)
            buk[i] = true;
    }
    vector<int> ans;
    int *pn=new int;
    cin>>*pn;
    for (int i(0); i < *pn; i++)
    {
        int x;
        cin >> x;
        if (buk[x])
            ans.push_back(x);
    }
    delete pn;
    pn=0;
    for(vector<int>::iterator ians=ans.begin();ians!=ans.end();ians++)
    cout<<*ians<<' ';
    return 0;
}