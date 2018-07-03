#include <bits/stdc++.h>

using namespace std;

int scoreOfParentheses(string S)
{
    stack<int> m_stack;
    m_stack.push(0);
    for(char c:S){
        if(c=='(')
            m_stack.push(0);
        else{
            int tmp=m_stack.top();
            m_stack.pop();
            int val=0;
            if(tmp>0)
                val=tmp*2;
            else
                val=1;
            m_stack.top()+=val;
        }   
    }
    return m_stack.top();
}

int main()
{
    int N;
    cin>>N;
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        cout<<scoreOfParentheses(s)<<endl;
    }
    return 0;
}