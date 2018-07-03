#include<bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

map<TreeNode*,pair<bool,TreeNode*> > parent;

vector<int> get_k_hop_son(TreeNode *root,int K){
    vector<int> res;
    if(root==NULL)
        return res;
    if(K==0){
        res.push_back(root->val);
        return res;
    }
    auto tmp=get_k_hop_son(root->left,K-1);
    res.insert(res.end(),tmp.begin(),tmp.end());
    tmp=get_k_hop_son(root->right,K-1);
    res.insert(res.end(),tmp.begin(),tmp.end());
    return res;
}

void dfs(TreeNode *root){
    if(root->left!=NULL){
        parent[root->left]=make_pair(0,root);
        dfs(root->left);
    }

    if(root->right!=NULL){
        parent[root->right]=make_pair(1,root);
        dfs(root->right);
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int K)
{
    if(root==NULL||target==NULL)
        return vector<int>();
    dfs(root);

    parent[root] = make_pair(0,(TreeNode*) NULL);

    vector<int> res;
    auto tmp=get_k_hop_son(target,K);
    res.insert(res.end(),tmp.begin(),tmp.end());

    // cout<<res.size()<<endl;

    int k=1;
    
    TreeNode* p = NULL;
    bool right_side = 0;
    p=parent[target].second;
    right_side=parent[target].first;
    while(p!=NULL && k<=K){
        // cout<<p->val<<","<<right_side<<endl;
        if(k==K){
            res.push_back(p->val);
            return res;
        }
        if(right_side)
            tmp=get_k_hop_son(p->left,K-k-1);
        else
            tmp=get_k_hop_son(p->right,K-k-1);
        res.insert(res.end(),tmp.begin(),tmp.end());
        //注意顺序不能调换，要先确定当前节点是父节点的左还是右
        right_side=parent[p].first;
        //才能把父节点当成当前节点
        p=parent[p].second;
        k++;
    }
    return res;
}

int main(){
    TreeNode *n0=new TreeNode(0);
    TreeNode *n1=new TreeNode(1);
    TreeNode *n2=new TreeNode(2);
    TreeNode *n3=new TreeNode(3);
    n0->left=n2;
    n0->right=n1;
    n1->left=n3;
    auto res=distanceK(n0,n3,3);
    for(auto i:res)
        cout<<i<<", ";
    cout<<endl;
    return 0;
}