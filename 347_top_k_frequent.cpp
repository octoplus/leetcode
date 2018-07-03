#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    for (int num : nums)
    {
        map[num]++;
    }
    vector<int> res;
    priority_queue< pair<int, int> > pq;
    for (auto it = map.begin(); it != map.end(); it++)
    {
        pq.push(make_pair(it->second, it->first));
        if (pq.size() > map.size() - k)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}

int main()
{
    int a[] = {1, 1, 1, 2, 2, 3};
    vector<int> nums(a, a + 6);
    vector<int> res = topKFrequent(nums, 2);
    for (int i : res)
        cout << i << endl;
    return 0;
}