#include<bits/stdc++.h>

using namespace std;

/**
 * 最初的想法就是用dfs，找到所有的阶梯之后，取最短的，但是这种办法一半的case都过不了
 * 接着根据题目分类写了bfs，但是到了高阶用例之后，就出现TLE和超出内存限制
 * 之后参考了别人的答案，写了剪枝版的bfs
 * 剪枝的原理就是：当bfs进入下一层的时候，之前层用过的单词，之后不可能再用了，因为如果在之后层过度到之前用过的单词，说明这条路径一定不是最短的
 * 但是注意同一层的不同路径可能会用相同的单词，所以一定要在进入下一层的时候才标记或者删除上一层用过的单词
 * 但是剪枝后面对一部分高级用例还是会TLE，再分析对比了
 */

bool diff(string a,string b){
    int n=a.size();
    int ans=0;
    for(int i=0;i<n;i++)
        if(a[i]!=b[i])
            ans++;
    return ans==1;
}

void show_queue(list<vector<string> >& q){
    for(auto i:q){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
    
}

void show_res(vector<vector<string> > &res_path){
    for(auto i: res_path){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void test1(){
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    auto res_path=findLadders("hit","cog",wordList);
    show_res(res_path);
}

void test2(){
    vector<string> wordList{"hot","dot","dog","lot","log"};
    auto res_path=findLadders("hit","cog",wordList);
    show_res(res_path);
}

void test3(){
    vector<string> wordList{"ted","tex","red","tax","tad","den","rex","pee"};
    auto res_path=findLadders("red","tax",wordList);
    show_res(res_path);
}

int main(){
    test3();
    return 0;
}