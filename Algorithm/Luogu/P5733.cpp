#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    string passage;
    string::iterator ip;
    cin>>passage;
    for(ip=passage.begin();ip!=passage.end();ip++)
        *ip=toupper(*ip);
    cout<<passage;
    return 0;
}