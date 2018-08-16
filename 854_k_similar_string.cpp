#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

/**
 * 这题也是bfs
 * 但是用了set来避免重复操作字符串
 */

int kSimilarity(string A, string B) {
    if(A==B) return 0;
    unordered_set<string> visit;
    queue<pair<string,int> >q;
    int n=A.size();
    int step = 0;

    int i=0;
    while(A[i]==B[i]) i++;

    q.push({A,i});
    visit.insert(A);
    while(!q.empty()){
        int len=q.size();
        for(int i=0;i<len;i++){
            string t=move(q.front().first);
            int idx=q.front().second;
            q.pop();

            if(t==B) return step;

            while(t[idx]==B[idx]) idx++;
            for(int i=idx+1;i<n;i++){
                if(t[i]==B[idx] && t[i]!=B[i]){
                    swap(t[idx],t[i]);
                    
                    if(visit.count(t)==0){
                        q.push({t,idx+1});
                        visit.insert(t);
                    }
                    swap(t[idx],t[i]);
                }
            }
        }
        step++;
    }
    return step;
}

int main(){
    // cout<<kSimilarity("aabc","abca")<<endl;
    // cout<<kSimilarity("ab","ba")<<endl;
    cout<<kSimilarity("abccaacceecdeea","bcaacceeccdeaae")<<endl;
    return 0;
}