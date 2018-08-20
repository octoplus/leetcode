#include<bits/stdc++.h>

using namespace std;

int singleNumber(vector<int>& nums) {
    int n=nums.size();
    vector<int> mask;
    vector<int> r(32,0);
    for(int i=0;i<32;i++){
        mask.push_back(1<<i);
    }    
    for(int i=0;i<n;i++){
        for(int j=0;j<32;j++){
            r[j]+=((nums[i]&mask[j])!=0);
        }
    }
    for(int i=0;i<32;i++){
        // cout<<r[i]<<" ";
        r[i]%=3;
    }
    // cout<<endl;
    int ans=0;
    for(int i=0;i<32;i++){
        ans+=r[i]*mask[i];
    }
    return ans;
}

int main(){
    vector<int> nums{2,2,3,2};
    cout<<singleNumber(nums)<<endl;
    return 0;
}