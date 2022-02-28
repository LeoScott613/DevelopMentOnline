#include <string>
#include <iostream>
int main()
{
    std::string str="Hello Worl";
    std::string::iterator sti;
    sti=str.end();
    *sti='d';
    std::cout<<str<<std::flush;
    return 0;
}