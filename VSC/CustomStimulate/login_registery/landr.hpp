//#pragma once
#include <string>
#include <iostream>
#ifndef LANDR_LHX
#define LANDR_LHX
using namespace std;
typedef std::string::iterator sti;
class user
{
    std::string encoding(std::string);

public:
    std::string username;
    std::string password;
};
extern int fileop(bool, user);
#endif
//ifndef is C/C++