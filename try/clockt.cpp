#include <ctime>
#include <iostream>
using namespace std;
int main() {
    int wait;
    cout<<"How long do you want to wait?:"<<endl;
    cin>>wait;
    clock_t start=clock();
    for(clock_t current=clock();(current-start)/CLOCKS_PER_SEC<wait;current=clock());
    cout<<"exit";
    return 0;
}