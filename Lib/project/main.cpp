#include "self.hpp"
//#include <iostream>
#include <vector>
using namespace std;
proj inpu()
{
    proj inp;
    cin>>inp.name;
    return inp;
}
int main()
{
    vector<proj> lhx;
    lhx.push_back(inpu());
    vector<proj>::iterator ilhx=lhx.begin();
    std::cout<<(*ilhx).name<<std::endl;
    return 0;
}