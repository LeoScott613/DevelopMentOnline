#include <iostream>
#include <iomanip>
#include <algorithm>
#define leng 1000
using namespace std;
class line {
public:
    int key;
    int time;
};
bool operator < (line i, line j) {
        return i.key<j.key;
}
int main() {
    double n;
    line duilie[leng];
    cin>>n;
    for(int i(0);i<n;i++)
        duilie[leng].key=i+1;

    for(int i(0);i<n;i++)
        cin>>duilie[i].time;
    sort(duilie,duilie+(int)n);

    double ans(0);
    for(int i(0);i<n-1;i++)
        ans+=duilie[i].time;
    
    for(int i(0);i<n;i++)
        cout<<duilie[i].key<<' ';
    cout<<'\n'<<setprecision(2)<<ans/n;
    return 0;
}