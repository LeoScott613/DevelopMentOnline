#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace lhx
{
    class proj
    {
    public:
        std::string name;

    private:
        void dis();
    };

    void proj::dis()
    {
        cout << "HelloProject!" << endl;
    }
}//namespace lhx