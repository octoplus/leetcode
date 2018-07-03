#include<bits/stdc++.h>

using namespace std;

struct Node{
    int p;
    int s;
    Node(int p,int s):p(p),s(s){}
    bool operator< (const Node r)const{
        return p < r.p;
    }
};

int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n=position.size();
    if(n<=1)
        return n;
    vector<Node> v;
    for(int i=0;i<n;i++){
        v.push_back(Node(position[i],speed[i]));
    }
    sort(v.begin(),v.end());
    
    int p=v[n-1].p;
    int s=v[n-1].s;
    float t= (target-p)/(float)s;
    int res=1;
    for(int i=n-2;i>=0;i--){
        int tmp_p=v[i].p;
        int tmp_s=v[i].s;
        float tmp_t=(target-tmp_p)/(float)tmp_s;
        if(tmp_t>t){
            t=tmp_t;
            res++;
        }
    }
    return res;
}

int main(){

}