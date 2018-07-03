#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int numberOfBoomerangs(vector<pair<int, int> > &points)
{
    int n = points.size();
    if (n < 3)
        return 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> m;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            int dx = points[i].first - points[j].first;
            int dy = points[i].second - points[j].second;
            int d = dx * dx + dy * dy;
            auto iter = m.find(d);
            if (iter == m.end())
                m[d] = 1;
            else
                m[d]++;
        }
        auto iter = m.begin();
        while (iter != m.end())
        {
            res += iter->second * (iter->second - 1);
            iter++;
        }
    }

    return res;
}

int main()
{
    vector<pair<int, int> > v;
    v.push_back(make_pair(0, 0));
    v.push_back(make_pair(1, 0));
    v.push_back(make_pair(2, 0));
    int res=numberOfBoomerangs(v);
    assert(2==res);
    cout<<res<<endl;
}