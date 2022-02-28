#include "landr.hpp"
#include <fstream>
std::string user::encoding(std::string passw)//inline function works differently
{
    sti ipass(passw.begin());
    for (; ipass != passw.end(); ipass++)
        *ipass -= 3;
    return passw;
}
extern int fileop(bool inorout, user data)
{
    // true for in(register), false for out(login)
    ofstream regista;
    regista.open("ku.dat",ios::app);//But what is ios::ate?
    string userna(user::encoding(data.username));
    string paswor(user::encoding(data.password));
    regista<<userna<<endl<<paswor<<endl<<'-'<<endl;
    regista.close();
    return 0;
}