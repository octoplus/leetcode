#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int,vector<TreeNode*> > level;
unordered_map<TreeNode*,TreeNode*> father;
int deepest=0;

void dfs(TreeNode *root,int i){
    if(i>deepest) deepest=i;
    if(root==NULL) return;
    auto iter = level.find(i);
    if(iter==level.end()){
        level[i]=vector<TreeNode*>();
    }
    level[i].push_back(root);
    if(root->left!=NULL){
        father[root->left]=root;
        dfs(root->left,i+1);
    }
    if(root->right!=NULL){
        father[root->right]=root;
        dfs(root->right,i+1);
    }
}

TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    if(root==NULL) return NULL;
    dfs(root,0);
    auto v=level[deepest];
    cout<<deepest<<","<<v.size()<<endl;
    unordered_set<TreeNode*> s(v.begin(),v.end());
    while(s.size()>1){
        cout<<s.size()<<endl;
        vector<TreeNode*> tmp;
        auto iter=s.begin();
        for(;iter!=s.end();iter++){
            tmp.push_back(father[*iter]);
        }
        cout<<tmp.size()<<endl;
        s.clear();
        cout<<s.size()<<endl;
        for(auto i=tmp.begin();i!=tmp.end();i++)
            s.insert(*i);
        cout<<s.size()<<endl;
    }
    return *s.begin();
}

int main(){
    TreeNode* t0=new TreeNode(0);
    TreeNode* t1=new TreeNode(1);
    TreeNode* t2=new TreeNode(2);
    t0->left=t1;
    t0->right=t2;
    auto res=subtreeWithAllDeepest(t0);
    cout<<res->val<<endl;
    return 0;
}