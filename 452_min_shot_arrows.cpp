#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

struct Node
{
    int id;
    int val;
    bool left;
    Node(int id, int val, bool left) : id(id), val(val), left(left) {}
    bool operator<(const Node r) const
    {
        if (val == r.val)
            return left > r.left;
        return val < r.val;
    }
};

int findMinArrowShots(vector<pair<int, int> > &points)
{
    vector<Node> v;
    unordered_map<int, bool> map;
    for (int i = 0; i < points.size(); i++)
    {
        v.push_back(Node(i, points[i].first, 1));
        v.push_back(Node(i, points[i].second, 0));
        map[i] = 1;
    }
    sort(v.begin(), v.end());
    int last = -1;
    int res = 0;
    for (int i = 0; i < points.size() * 2; i++)
    {
        if (!v[i].left && map[v[i].id])
        {
            res += 1;
            for (int j = i; j > last; j--)
                map[v[j].id] = 0;
            last = i;
        }
    }
    return res;
}

int main()
{

    return 0;
}