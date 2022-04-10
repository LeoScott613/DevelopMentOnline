#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    //pay attention to the scale of data
    double n;
    double a,b;//factor
    double deno;//denominator
    a=(1+sqrt(5))/2;
    b=(1-sqrt(5))/2;
    deno=sqrt(5);

    cin>>n;
    double fn=(pow(a,n)-pow(b,n))/deno;
    cout<<fixed<<setprecision(2)<<fn<<endl;
    return 0;
}