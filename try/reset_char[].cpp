#include <iostream>
#include <string>
// using namespace std;
int main()
{
    char temp[10] = {'-', '1', '2', '3'};
    if (temp[0] == '-')
        temp[0] = '\1'; //\1:start of the text
    temp[3] = '\1';
    std::string str = std::string(temp);
    temp[3] = '\0';
    std::string str2 = std::string(temp);
    temp[0] = temp[3] = '\0';
    std::string str3 = std::string(temp);
    temp[0] = temp[3] = '\1';
    std::cout << temp << std::endl
              << str.size() << std::endl
              << str2.size() << std::endl
              << str3.size() << std::endl;
    return 0;
}