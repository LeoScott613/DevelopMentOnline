#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define t j++
using namespace std;
int buk[21];
int main()
{
    map<string,int> madp;
    int j(0);
    madp["zero"]=t;madp["one"]=madp["a"]=madp["another"]=madp["first"]=t;
    madp["two"]=madp["both"]=madp["second"]=t;madp["three"]=madp["third"]=t;
    madp["four"]=t;madp["five"]=t;madp["six"]=t;madp["seven"]=t;
    madp["eight"]=t;madp["night"]=t;madp["ten"]=t;madp["eleven"]=t;
    madp["twelve"]=t;madp["thirteen"]=t;madp["fourteen"]=t;madp["fifteen"]=t;
    madp["sixteen"]=t;madp["seventeen"]=t;madp["eighteen"]=t;
    madp["nineteen"]=t;madp["twenty"]=t;
    string word;
    memset(buk,0,sizeof(buk));
    for(int i(0);i<6;i++)
    {
        cin>>word;
        if(madp.count(word))
            buk[madp[word]]++;
    }
    vector<int> v;
    vector<int>::iterator iv;
    for(int i(0);i<21;i++)
        for(int j(0);j<buk[i];j++)
            v.push_back((i*i)%100);
    if(v.size()==0)
    {
        cout<<0;
        return 0;
    }
    sort(v.begin(),v.end());
    for(iv=v.begin();*iv==0;iv++);
    cout<<*iv;//the first one to output isn't with a 0
    for(iv++;iv<v.end();iv++)
        printf("%02d",*iv);
    return 0;
}