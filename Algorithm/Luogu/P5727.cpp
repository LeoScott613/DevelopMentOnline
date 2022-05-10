#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<long> ans;
    long n;
    cin>>n;
    ans.push_back(n);
    while(n>1) {
        if(n%2) 
            n=n*3+1;
        else n/=2;
        ans.push_back(n);
    }
    for(vector<long>::iterator ia=ans.end()-1;ia>=ans.begin();ia--)
        cout<<*ia<<' ';
    return 0;
}
//One question according to one code page, so short, so boring
//Every time I finished a program, what was I programming for?
//I review this question, and my answer is--I don't code for fitting in the answer of questions, but I answering the question for coding.