#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int k;
    cin>>k;
    vector<int> result;
    for(int i(10000);i<=30000;i++)
    {
        int s(0),baci;
        int sub(0);
        for(int h(0);h<3;h++)
        {
            baci=i/pow(10,h);
            for(int j(0);j<3;j++)
            {
                s+=baci%10*pow(10,j);
                baci/=10;
            }
            if(s%k!=0)
                break;
            else
                sub++;
        }
        if(sub==3)
            result.push_back(i);
    }
    if(result.empty())
        cout<<"No";
    else
        for(vector<int>::iterator ir(result.begin());ir!=result.end();ir++)
            cout<<*ir<<endl;
    return 0;
}