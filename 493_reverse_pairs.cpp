#include<bits/stdc++.h>

using namespace std;

/**
 * 求逆序对，最开始很直观地就想到了用归并
 * 但是没有考虑到负值的情况
*/

int ans=0;

void print_vec(vector<int>& nums){
    for(int i:nums)
        cout<<i<<",";
    cout<<endl;
}

void helper(vector<int>& nums,vector<int>& b,int l,int r){
    if(l==r)
        return;
    int mid=(l+r)/2;
    // cout<<l<<","<<r<<","<<mid<<endl;
    // print_vec(nums);
    helper(nums,b,l,mid);
    helper(nums,b,mid+1,r);
    // print_vec(nums);
    // 统计重要逆序对的数量
    int k1=l,k2=mid+1;
    for(k1=l;k1<=mid;k1++){
        while(k2<=r&&nums[k2]<nums[k1]/2.0)
            k2++;
        ans+=k2-mid-1;
    }
    // 归并过程
    int i=l;
    k1=l;
    k2=mid+1;
    while(k1<=mid && k2<=r){
        if(nums[k1] <= nums[k2])
            b[i++]=nums[k1++];
        else 
            b[i++]=nums[k2++];
    }
    while(k1<=mid){
        b[i++]=nums[k1++];
    }
    while(k2<=r){
        b[i++]=nums[k2++];
    }
    for(i=l;i<=r;i++){
        nums[i]=b[i];
    }
    // cout<<l<<","<<r<<","<<mid<<endl;
    // print_vec(nums);
    // cout<<ans<<endl;
    // cout<<endl;
}

int reversePairs(vector<int>& nums) {
    int n=nums.size();
    if(n<=1)
        return 0;
    ans=0;
    vector<int> b(n);
    helper(nums,b,0,n-1);
    return ans;
}

int main(){
    vector<int> v{1,3,2,3,1};
    // vector<int> v{2,4,3,5,1};
    // vector<int> v{-5,-5};
    // vector<int> v{2147483647,2147483647,2147483647,2147483647,2147483647,2147483647};
    cout<<reversePairs(v)<<endl;
    return 0;
}