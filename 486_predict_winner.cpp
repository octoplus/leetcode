#include<bits/stdc++.h>

using namespace std;

int helper(vector<int>& nums,int i,int j,int player){
    if(i==j){
        if(player==2)
            return -nums[i];
        else
            return nums[i];
    }
    if(player==1)
        return max(nums[i]+helper(nums,i+1,j,2),nums[j]+helper(nums,i,j-1,2));
    else
        return min(-nums[i]+helper(nums,i+1,j,1),-nums[j]+helper(nums,i,j-1,1));
}

bool PredictTheWinner(vector<int>& nums) {
    int res=helper(nums,0,nums.size()-1,1);
    cout<<res<<endl;
    return res>=0;
}

int main(){
    int a[]={1,5,233,7};
    vector<int> nums;
    for(int i:a){
        nums.push_back(i);
    }
    cout<<PredictTheWinner(nums)<<endl;
    return 0;
}