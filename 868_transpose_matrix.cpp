#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& A) {
    int n=A.size(),m=A[0].size();
    vector<vector<int>> res(m);
    for(int j=0;j<m;j++){
        vector<int> tmp(n);
        for(int i=0;i<n;i++){
            tmp[i]=A[i][j];
        }
        res[j]=tmp;
    }
    return res;
}

int main(){
    vector<vector<int> > v{{1,2,3},{4,5,6},{7,8,9}};
    auto res=transpose(v);
    for(auto i:res){
        for(auto j:i){
            cout<<j<<",";
        }
        cout<<endl;
    }
    return 0;
}