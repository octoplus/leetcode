#include<bits/stdc++.h>

using namespace std;

int res;

void dfs(int n, int d, int mid,int left,int right){
    for(int i=0;i<n;i++){
        int flag=1<<i;
        if(((mid |left|right) & flag) ==0) {
            if(d==n)      
                res++;
            else{
                dfs(n,d+1, (mid|flag),(left|flag)<<1,(right|flag)>>1);
            }
        }
    }
}

int totalNQueens(int n) {
    dfs(n,1,0,0,0);
    return res;
}

int main(){
    cout<<totalNQueens(8)<<endl;
    return 0;
}