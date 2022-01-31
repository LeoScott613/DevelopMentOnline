#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int line,x;
    vector<int> data;
    bool switz(false);
    cin>>line;
    while(data.size()<line*line)
    {
        cin>>x;
        while(x&&data.size()<line*line)
        {
            if(switz) data.push_back(1);
            else data.push_back(0);
            x--;
        }
        switz=!switz;
    }
    vector<int>::iterator iv(data.begin());
    while(iv!=data.end())
    {   
        for(int i(0);i<line&&iv!=data.end();i++,iv++)
            cout<<*iv;
        cout<<endl;
    }
    return 0;
}