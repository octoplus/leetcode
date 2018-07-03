#include <bits/stdc++.h>

using namespace std;

bool PredictTheWinner(vector<int> &nums)
{
    int n = nums.size();
    int dp[n][n];
    int res = 0;
    int label = n % 2 == 0 ? -1 : 1;
    cout<<label<<endl;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = label * nums[i];
        cout<<i<<","<<i<<","<<dp[i][i]<<endl;
    }
    for (int l = 1; l < n; l++)
    {
        bool flag = (l+1) % 2 == n % 2;
        for (int i = 0; i+l < n; i++)
        {
            if (flag)
                dp[i][i + l] = max(dp[i + 1][i + l]+nums[i], dp[i][i + l - 1]+nums[i+l]);
            else
                dp[i][i + l] = min(dp[i + 1][i + l]-nums[i], dp[i][i + l - 1]-nums[i+l]);
            cout<<i<<","<<i+l<<","<<dp[i][i+l]<<endl;
        }
    }
    return dp[0][n - 1] >= 0;
}

int main()
{
    int a[] = {1, 5, 2};
    vector<int> nums;
    for (int i : a)
    {
        nums.push_back(i);
    }
    cout << PredictTheWinner(nums) << endl;
    return 0;
}