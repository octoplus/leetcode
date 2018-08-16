#include<bits/stdc++.h>

using namespace std;

string decodeString(string s){
    int n=s.size();
    stack<pair<int,string> > stk;
    stk.push(make_pair(1,""));
    for(int i=0;i<n;i++){
        if(isdigit(s[i])){
            int tmp=0;
            while(isdigit(s[i])){
                tmp=tmp*10+s[i]-'0';
                i++;
            }
            stk.push(make_pair(tmp,""));
        }else if(isalpha(s[i])){
            stk.top().second+=s[i];
        }else{
            auto tp=stk.top();
            stk.pop();
            for(int k=0;k<tp.first;k++)
                stk.top().second+=tp.second;
        }
    }
    return stk.top().second;
}

int main(){
    cout<<decodeString("3[a]2[bc]")<<endl;
    cout<<decodeString("3[a2[c]]")<<endl;
    cout<<decodeString("2[abc]3[cd]ef")<<endl;
    return 0;
}