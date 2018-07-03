#include <bits/stdc++.h>

using namespace std;

int minMoves(vector<int> &nums)
{
    if (nums.size() <= 1)
        return 0;
    int sum = 0;
    int min_val = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        min_val = min_val > nums[i] ? nums[i] : min_val;
    }
    return sum - min_val * nums.size();
}

int main()
{

    return 0;
}