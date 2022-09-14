#include <iostream>
#include <map>
#include <vector>
using namespace std;
long f(long x,long y);
map<pair<int,int>,int> note;
long hx,hy;
const int horse_dif[]={0,0, -1,-2, 1,-2, -2,-1, 2,-1, -2,1, 2,1, -1,2, 1,2};
const int hdif_leng=18;
vector<pair<long,long> > horse_cord;
int main() {
    long x,y;
    cin>>x>>y>>hx>>hy;
    for(int i(0);i<hdif_leng;i+=2) {
        pair<long,long> newer;
        newer.first=hx+horse_dif[i];
        newer.second=hy+horse_dif[i+1];
        horse_cord.push_back(newer);
    }
    cout<<f(x,y);
}
long f(long x, long y) {
    pair<long,long> passby;
    passby.first=x;
    passby.second=y;
    bool existence=false;
    for(vector<pair<long,long> >::iterator ih=horse_cord.begin();ih!=horse_cord.end();ih++)
        if(*ih==passby)
            existence=true;
    if(existence)
        return 0;

    long ra,rb;

    pair<long,long> cord;
    cord.first=x;
    cord.second=y;

    if(note.count(cord))
        return note[cord];
    
    (x>1)?(ra=f(x-1,y)):(ra=1);
    (y>1)?(rb=f(x,y-1)):(rb=1);
    note[cord]=ra+rb;
    return note[cord];
}
