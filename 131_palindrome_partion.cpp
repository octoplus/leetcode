#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

/**
 * 整成n^2的复杂度，还不如直接检查是否回文来的快，尴尬
 */

unordered_map<int,list<int> > m;
vector<vector<string> > res;
string _s;

void helper(vector<string> &prefix,int l){
    int n=_s.size();
    if(l==n){
        res.push_back(prefix);
        return ;
    }
    for(int i:m[l]){
        vector<string> tmp(prefix);
        tmp.push_back(_s.substr(l,i-l));
         helper(tmp,i);
    }
}

vector<vector<string> > partition(string s) {
    int n=s.size();
    _s=s;
    bool f[n][n];
    memset(f,1,sizeof(f));
    for(int i=0;i<n;i++){
        m[i]=list<int>();
        m[i].push_back(i+1);
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            f[i][i+l-1]= f[i+1][i+l-2] && s[i]==s[i+l-1];
            if(f[i][i+l-1])
                m[i].push_back(i+l);
        }
    }
    vector<string> _;
    helper(_,0);
    return res;
}

int main(){
    string s="aab";
    auto res=partition(s);
    for(auto v:res){
        for(string i:v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}