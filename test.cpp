#include<bits/stdc++.h>
using namespace std;

/**
 * 测试结果说明，不要直接对容器里的元素进行move操作!!
*/

void show_vector(vector<int> &a){
    for(int i:a)
        cout<<i<<" ";
    cout<<endl;
}

int main(){
    list<vector<int> > l;
    l.push_back({1,2,3});
    l.push_back({4,5,6});
    l.push_back({7,8,9});
    cout<<l.size()<<endl;
    vector<int> t1 = move(l.front());
    cout<<l.size()<<endl;
    show_vector(t1);
    cout<<endl;
    for(auto i:l){
        show_vector(i);
    }

    vector<int> t2 = move(l.front());
    cout<<l.size()<<endl;
    show_vector(t2);
    cout<<endl;
    for(auto i:l){
        show_vector(i);
    }
    
    
    return 0;
}