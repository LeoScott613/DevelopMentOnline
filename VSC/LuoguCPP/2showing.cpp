#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    string line="";
    int L,R;
    cin>>L>>R;
    int i;
    for(i=L;i<=R;i++){
        char buff[100000];
        sprintf(buff,"%d",i);
        line+=string(buff);
    }
    i=line.size();
    int n(0),count(0);
    while(n<i){
        if(line[n]=='2')
            count++;
        n++;
    }
    cout<<count<<endl;
    return 0;
}