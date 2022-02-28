#include <iostream>
using namespace std;
const int maxn(50);
int main()
{
    int cycle[maxn][3],points[2][2],n;
    cin>>n;
    for(int i(0);i<3;i++)
        for(int j(0);j<n;j++)
            cin>>cycle[j][i];
    cin>>points[0][0]>>points[0][1]>>points[1][0]>>points[1][1];
    int C(  (points[0][0]-points[1][0])*points[0][1]-(points[0][1]-points[1][1])*points[0][0]  );
    int cross(0);
    for(int i(0);i<n;i++)
    {
        int dist=(points[0][1]-points[1][1])*cycle[i][0]-(points[0][0]-points[1][0])*cycle[i][1]+C;
        if(dist<cycle[i][2])
            cross+=2;
        else if(dist==cycle[i][2])
            cross;//´ý¶¨
    }
    cout<<cross;
    return 0;
}

    
