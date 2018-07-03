#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

static auto hint = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class LRUCache
{
    int capacity;
    unordered_map<int, list<pair<int, int> >::iterator> cache;
    list<pair<int, int> > l;

  public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        auto iter = cache.find(key);
        if (iter == cache.end())
            return -1;
        l.splice(l.begin(), l, iter->second);
        return iter->second->second;
    }

    void put(int key, int value)
    {
        auto iter = cache.find(key);
        if (iter != cache.end())
        {
            l.splice(l.begin(), l, iter->second);
            iter->second->second = value;
            return;
        }
        if (cache.size() == capacity)
        {
            int key_to_del = l.back().first;
            l.pop_back();
            cache.erase(key_to_del);
        }
        l.emplace_front(key, value);
        cache[key] = l.begin();
    }
};

int main()
{

    return 0;
}