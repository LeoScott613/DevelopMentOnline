#include <iostream>
#include <vector>
#include <cmath>
// Input Pro1 Op1 Pro2 Op2

/*
Pro includes:
1.process data in vector game;
2.gave out W,L;
3.store W,L in vector wl;
4.Until vector game ends
*/

using namespace std;

vector<int> game;
vector<int> wl;
vector<int>::const_iterator iter;
vector<int>::const_iterator ending;
vector<int>::const_iterator wlb;
vector<int>::const_iterator wle;

int w(0), l(0);

int inpu() // input into a vector
{
    char c;
    cin >> c;
    if (c == 'W')
        return 1;
    else if (c == 'L')
        return 0;
    else if (c == 'E')
        return -1;
}

int wlop()
{
    wl.push_back(w);
    wl.push_back(l);
    w = l = 0;
    return 0;
    /*if (abs(w - l) >= 2)
    {
        wl.push_back(w);
        wl.push_back(l);
        w = l = 0;
    }
    else if (abs(w - l) < 2)
    {
        while (iter < ending && abs(w - l) < 2)
        {
            if (*iter == 1)
                w++;
            else if (*iter == 0)
                l++;
            iter++;
        }
    }*/
}

int main()
{
    while (1)
    {
        game.push_back(inpu());
        ending = game.end();
        if (*(--ending) == -1)
            break;
    } // Input, ends
    ending++;
    int j(0);            // counting times
    iter = game.begin(); // Must do it after you gave numbers to game
    while (iter < ending)
    {
        j = 0; // or j=10
        while (iter < ending && w < 11 && l < 11)
        {
            if (*iter == 1)
                w++;
            else if (*iter == 0)
                l++;
            iter++;
            j++;
        }
        while (iter < ending && abs(w - l) < 2)
        {
            if (*iter == 1)
                w++;

            else if (*iter == 0)
                l++;
            iter++;
        }
        wlop();
    } // Pro1, ends
    wle = wl.end();
    wle--;
    for (wlb = wl.begin(); wlb < wle; wlb += 2)
        cout << *wlb << ':' << *(wlb + 1) << endl;
    cout << endl; // Op1,ends

    vector<int>::size_type round = wl.size();
    iter = game.begin();
    ending = game.end();
    while (iter < ending)
    {
        j = 0; // or j=20
        while (iter < ending && w < 21 && l < 21)
        {
            if (*iter == 1)
                w++;
            else if (*iter == 0)
                l++;
            iter++;
            j++;
        }
        while (iter < ending && abs(w - l) < 2)
        {
            if (*iter == 1)
                w++;

            else if (*iter == 0)
                l++;
            iter++;
        }
        wlop();
    }

    wle = wl.end();
    wlb = wl.begin();
    for (j = 0; j < round; j++)
        wlb++;
    for (wle--; wlb < wle; wlb += 2)
        cout << *wlb << ':' << *(wlb + 1) << endl;
    return 0;
}