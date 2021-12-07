#include "self.hpp"
//#include <iostream>
#include <vector>
using namespace std;
lhx::proj inpu()
{
    lhx::proj inp;
    cin>>inp.name;
    return inp;
}
int main()
{
    vector<lhx::proj> lh;
    lh.push_back(inpu());
    vector<lhx::proj>::iterator ilh=lh.begin();
    std::cout<<(*ilh).name<<std::endl;
    return 0;
}