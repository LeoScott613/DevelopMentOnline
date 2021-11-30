#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n(0),i(1),sumup(0);
    for(;i<=100;i++,n++)
    sumup+=(pow(-1,n)*i);
    cout<<"1-2+3-4...-100 = "<<sumup<<endl;
    system("pause");
    return 0;
}