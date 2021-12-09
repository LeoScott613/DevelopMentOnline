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
/*
inline std::string user::encoding(std::string passw)//inline function works differently
{
    sti ipass(passw.begin());
    for (; ipass != passw.end(); ipass++)
        *ipass -= 3;
    return passw;
}   //Problem:Multiple definition
*/
extern int fileop(bool, user);
#endif
//ifndef is C/C++