#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>

using namespace std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
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
            return top.size();
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
    return 0;
}

int main(){
    
    return 0;
}