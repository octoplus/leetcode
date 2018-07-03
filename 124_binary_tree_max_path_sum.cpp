#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int best;

int helper(TreeNode *root){
    int local_best;
    if(root->left==NULL && root->right==NULL){
        local_best=root->val;
        best=local_best>best?local_best:best;
        return local_best;
    }
    else if(root->left!=NULL && root->right==NULL){
        int res=helper(root->left);
        local_best=max(max(res,root->val),res+root->val);
        best=local_best>best?local_best:best;
        return max(root->val+res,root->val);
    }
    else if(root->left==NULL && root->right!=NULL){
        int res=helper(root->right);
        local_best=max(max(res,root->val),res+root->val);
        best=local_best>best?local_best:best;
        return max(root->val+res,root->val); 
    }
    int right_res=helper(root->right);
    int left_res=helper(root->left);
    int res=root->val;
    if(res<left_res)
        res=left_res;
    if(res<right_res)
        res=right_res;
    if(res<left_res+root->val)
        res=left_res+root->val;
    if(res<right_res+root->val)
        res=right_res+root->val;
    if(res<right_res+root->val+left_res)
        res=right_res+root->val+left_res;
    best=res>best?res:best;
    return max(max(right_res+root->val,left_res+root->val),root->val);
}

int maxPathSum(TreeNode *root)
{
    best=root->val;
    helper(root);
    return best;
}

int main()
{

    return 0;
}