#pragma once
#include <string>
#include <iostream>
using namespace std;
class proj
{
public:
    std::string name;

private:
    void dis();
};

void proj::dis()
{
    cout<<"HelloProject!"<<endl;
}