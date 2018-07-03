#include <bits/stdc++.h>

using namespace std;

bool lemonadeChange(vector<int> &bills)
{
    int c5 = 0, c10 = 0, c20 = 0;
    for (int b : bills)
    {
        if (b == 5)
            c5++;
        else if (b == 10)
        {
            if (c5 <= 0)
                return 0;
            c10++;
            c5--;
        }
        else
        {
            if (c5 > 0 && c10 > 0)
            {
                c5--;
                c10--;
                c20++;
            }
            else if (c5 >= 3)
            {
                c5 -= 3;
                c20++;
            }
            else
                return 0;
        }
    }
    return 1;
}

int main()
{

    return 0;
}