#include <string>
#include <iostream>
using namespace std;
int main(){
    unsigned long long t1(1),t2(1),t3;
    int n;
    cin>>n;
    try{
        if(n<=0){
            const string errors("Hello you have trigered an exception.(Don't input negative number)");
            throw errors;
        }

    }
    catch(string err){
        cout<<err<<endl;
        return -1;
    }
    if(n<=2){
        cout<<t1<<' '<<t2;
        return 0;
    }
    cout<<t1<<' '<<t2<<' ';
    while(n-2>0){
        t3=t2+t1;
        cout<<t3<<' ';
        swap(t1,t2);
        swap(t2,t3);
        n--;
    }
    return 0;
}