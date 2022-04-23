/**
 * @file frog.cpp
 * @author Leo Scott
 * @date 2022-04-23
 * @remark website: https://juejin.cn/post/6951922898638471181
 */
#include <iostream>
#include <map>
using namespace std;
map<int,int> notepad;
const pair<int,int> one(1,1);
const pair<int,int> two(2,2);
pair<int,int> newNote;
int jumpPosibi(int level) {
    if(level==1) {
        notepad.insert(one);
        return 1;
    }
    else if(level==2) {
        notepad.insert(two);
        return 2;
    }

    int capsuleA,capsuleB;
    map<int,int>::iterator pos, endofmap=notepad.end();

    pos=notepad.find(level-1);
    if(pos!=endofmap) 
        capsuleA=(*pos).second;
    else {
        newNote.first=level-1;
        newNote.second=capsuleA=jumpPosibi(level-1);
        notepad.insert(newNote);
        endofmap=notepad.end();
    }

    pos=notepad.find(level-2);
    if(pos!=endofmap) 
        capsuleB=(*pos).second;
    else {
        newNote.first=level-2;
        newNote.second=capsuleB=jumpPosibi(level-2);
        notepad.insert(newNote);
        endofmap=notepad.end();
    }
    return capsuleA+capsuleB;
}
int main() {
    int n;
    cin>>n;
    cout<<jumpPosibi(n)<<endl;
    return 0;
}
