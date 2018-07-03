#include <bits/stdc++.h>

using namespace std;

int peakIndexInMountainArray(vector<int> &A)
{
    int j = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] > A[j])
            j = i;
    }
    return j;
}

int main()
{

    return 0;
}