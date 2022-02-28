#include <iostream>
#include <vector>
int input()        //An easy templete solving the input of vector
{
    int x;
    std::cin >> x;
    return x;
}
int main()
{
    std::vector<int> arr;      //You can define the length you input
    int i(0), j(0), n;
    std::cin >> n;
    while (i < n)
    {
        arr.push_back(input());
        i++;
    }
    for (i = 0; i < arr.size() - 1; i++)   //Core of selection sort
    {
        int min = i;
        for (j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[min])
                min = j;
        std::swap(arr[i], arr[min]);     //C++ only, when include iostream and using namespace std;
    }
    for(i=0;i<arr.size();i++)     //You cannot directly "cout<<arr"
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;         //Extra in problem but essential in developing 
    return 0;
}

/*                         My bug version
#include <iostream>
using namespace std;
int main()
{
    int a[10], i;
    for (i = 0; i < 10; i++)
        cin >> a[i];
    int j, mini, point = 0, tf;
    for (i = 0; i < 10; i++)
    {
        mini = a[i];
        for (j = i; j < 10; j++)
            if (a[j] < mini)
            {
                mini = a[j];
                point = j;
            }
        tf = a[i];
        a[i] = mini;
        a[point] = tf;
    }
    for (i = 0; i < 10; i++)
        cout << " " << a[i];
    return 0;
}
*/