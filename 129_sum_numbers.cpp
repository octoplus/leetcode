#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(TreeNode *root, int prefix){
    int tmp=prefix*10+root->val;
    if(root->right==NULL && root->left==NULL)
        return tmp; 
    int ans=0;
    if(root->left!=NULL)
        ans+=helper(root->left,tmp);
    if(root->right!=NULL)
        ans+=helper(root->right,tmp);
    return ans;
}

int sumNumbers(TreeNode* root) {
    if(root==NULL) return 0;
    return helper(root,0);
}

int main()
{

    return 0;
}