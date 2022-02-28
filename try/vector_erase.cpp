#include <iostream>
#include <vector>
int main()
{
    std::vector<int> ok;
    std::vector<int>::iterator eras;
    int i = 0;
    for (i = 0; i < 10; i++)
        ok.push_back(i);

    for (eras = ok.begin(); eras != ok.end(); eras++)
        if (*eras % 2 == 0)
        {
            eras = ok.erase(eras);//ok.erase returns the next iterator of the deleted.
        }
    for (eras = ok.begin(); eras != ok.end(); eras++)
        std::cout << *eras << std::endl;
    return 0;
}