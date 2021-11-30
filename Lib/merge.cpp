#include <iostream>
using namespace std;
int origin[5]={332,31,445,66,78},sorted[5];
void merge(int left,int right)//left is 0, right is the length of the array(not reduce 1)
{
    if(right-left<=1)
    return;
    int mid=left+(right-left>>1);
    merge(left,mid);
    merge(mid,right);
    int l=left,m=mid,l_=left;
    while(l_<right)
    {
        if(l>=mid)
            sorted[l_++]=origin[m++];
        else if(m<right&&origin[m]<origin[l])
            sorted[l_++]=origin[m++];
        else
            sorted[l_++]=origin[l++];
    }
    for(int i=left;i<right;++i)
    origin[i]=sorted[i];
}
int main()
{
    merge(0,5);
    for(int j(0);j<5;j++)
    {
        cout<<origin[j]<<' ';
    }
}