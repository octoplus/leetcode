#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> m;
    int ans=0;
    for(int i:nums){
        if(m.find(i)==m.end()){
            int left= m.find(i-1)==m.end()?0:m[i-1];
            int right=m.find(i+1)==m.end()?0:m[i+1];
            int sum=left+right+1;
            ans=max(ans,sum);
            m[i]=sum;
            m[i-left]=sum;
            m[i+right]=sum;
        }
    }
    return ans;
}

int main(){
    vector<int> v{100,4,200,1,3,2};
    cout<<longestConsecutive(v)<<endl;
    return 0;
}