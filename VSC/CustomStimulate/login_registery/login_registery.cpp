#include "landr.hpp"
int main()
{
    string linetip = "*---------*";
    string usertip = "Username:", usirname;
    string passtip = "Password:", pasword;
    user for_login, for_registery;
    cout << "Do you want to register?:(Y/N)";
    char c;
    c = getchar();
    cout << linetip << endl
         << usertip;
    cin >> usirname;
    cout << endl << passtip;
    cin >> pasword;
    if(c=='Y'||c=='y')
    {
        for_registery.username=usirname;
        for_registery.password=pasword;
        fileop(true,for_registery);
    }
    return 0;
}