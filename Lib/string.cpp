#include <string>
#include <iostream>
using namespace std;
const int num = 3;
int main()
{
    // initialization
    string str("......");
    string stt(str);
    string sty(6, '.');
    string stu(str, 5); // start from 0;
    string sti(str, 2, 4);

    cout << str << endl;
    cout << stt << endl;
    cout << sty << endl;
    cout << stu << endl;
    cout << sti << endl;

    // operation
    stu.~string();
    // cout << stu << endl;  Don't do it.
    swap(sti, sty);
    getline(cin, str);
    str.append(stt);
    cin >> sty;
    cout << str << endl;
    cout << sty << endl;

    return 0;
}