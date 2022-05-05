/**
 * @file frog_2.cpp
 * @author Leo Scott
 * @version 2
 */
#include <iostream>
#include <map>
using namespace std;
map<int,int> notepad;
map<int,int>::iterator ia,ib,ie;
pair<int,int> porter;
int jumpTo(int levo) {
    if(levo<=0) {
        return 0;
    }
    else if(levo==1) {
        porter.first=porter.second=1;
        notepad.insert(porter);
        return 1;
    }
    else if(levo==2) {
        porter.first=porter.second=2;
        notepad.insert(porter);
        return 2;
    }
    ia=notepad.find(levo-1);
    ib=notepad.find(levo-2);
    ie=notepad.end();
    int jumpToA(-1),jumpToB(-1);
    if(ia==ie) jumpToA=jumpTo(levo-1);
    else jumpToA=(*ia).second;
    if(ib==ie) jumpToB=jumpTo(levo-2);
    else jumpToB=(*ib).second;
    
    porter.first=levo;
    porter.second=jumpToA+jumpToB;
    return jumpToA+jumpToB;
    //return jumpTo(levo-1)+jumpTo(levo-2);
}

int main() {
    int n;
    cin>>n;
    cout<<jumpTo(n)<<endl;
    return 0;
}