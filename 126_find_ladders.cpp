#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

/**
 * 最初的想法就是用dfs，找到所有的阶梯之后，取最短的，但是这种办法一半的case都过不了
 * 接着根据题目分类写了bfs，但是到了高阶用例之后，就出现TLE和超出内存限制
 * 之后参考了别人的答案，写了剪枝版的bfs
 * 剪枝的原理就是：当bfs进入下一层的时候，之前层用过的单词，之后不可能再用了，因为如果在之后层过度到之前用过的单词，说明这条路径一定不是最短的
 * 但是注意同一层的不同路径可能会用相同的单词，所以一定要在进入下一层的时候才标记或者删除上一层用过的单词
 * 但是剪枝后面对一部分高级用例还是会TLE，再分析对比了别人的思路，发现是单词对比复杂度的问题
 * 假设单词长度k，备选集长度n
 * 则按照每个备选进行字符串对比，则一条路径进行分支的复杂度是nk
 * 而按照每个位置进行26个字母变换生成，则复杂度是26k
 * 按照这种优化能过所有case，但是速度还是偏慢
 */

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
    vector<vector<string> > res;
    int k=beginWord.size();
    unordered_map<string,bool> m;
    for(string s:wordList)
        m[s]=1;
    // list<string> visited;
    unordered_set<string> visited;
    list<vector<string> > q;
    q.push_back({beginWord});
    int level=0;
    int shortest=INT_MAX;
    while(!q.empty()){
        // show_queue(q);
        vector<string> top=q.front();
        q.pop_front();
        if(top.size()>shortest)
            break;
        if(top.size()>level){
            level=top.size();
            for(string i:visited)
                m[i]=0;
            visited.clear();
        }
        string last=top.back();
        if(last==endWord){
            res.push_back(top);
            shortest=min(shortest,(int)top.size());
            continue;
        }
        for(int i=0;i<k;i++){
            string tmp=last;
            for(char c='a';c<='z';c++){
                tmp[i]=c;
                if(m.find(tmp)!=m.end() && m[tmp]){
                    vector<string> tmp_path(top);
                    tmp_path.push_back(tmp);
                    q.push_back(tmp_path);
                    visited.insert(tmp);
                }
            }
        }

    }
    return res;
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
    // test1();
    // test2();
    test3();
    return 0;
}