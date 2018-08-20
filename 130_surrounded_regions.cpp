#include<bits/stdc++.h>

using namespace std;

template<typename T>
void show(vector<vector<T> > & v){
    int n=v.size();
    int m=v[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<v[i][j]<<' ';
        cout<<endl;
    }
    cout<<endl;
}

void dfs(vector<vector<char> >& board,vector<vector<bool> >& f,int x,int y){
    int n=board.size();
    int m=board[0].size();
    f[x][y]=false;
    if(x-1>=0 && board[x-1][y]=='O' && f[x-1][y])
        dfs(board,f,x-1,y);
    if(y-1>=0 && board[x][y-1]=='O' && f[x][y-1])
        dfs(board,f,x,y-1);
    if(y+1<m && board[x][y+1]=='O' && f[x][y+1])
        dfs(board,f,x,y+1);
    if(x+1<n && board[x+1][y]=='O' && f[x+1][y])
        dfs(board,f,x+1,y);
}

void solve(vector<vector<char> >& board) {
    int n=board.size();
    if(n<=0) return;
    int m=board[0].size();
    if(m<=0) return;
    vector<vector<bool> > f;
    for(int i=0;i<n;i++)
        f.push_back(vector<bool>(m,1));
    // show<bool>(f);
    for(int i=0;i<m;i++)
        if(f[0][i] && board[0][i]=='O')
            dfs(board,f,0,i);
    for(int i=0;i<m;i++)
        if(f[n-1][i] && board[n-1][i]=='O')
            dfs(board,f,n-1,i);
    for(int j=0;j<n;j++)
        if(f[j][0] && board[j][0]=='O')
            dfs(board,f,j,0);
    for(int j=0;j<n;j++)
        if(f[j][m-1] && board[j][m-1]=='O')
            dfs(board,f,j,m-1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O'&& f[i][j])
                board[i][j]='X';
        }
    }
}

int main(){
    vector<vector<char> > board;
    board.push_back({'X','X','X','X'});
    board.push_back({'X','O','O','X'});
    board.push_back({'X','X','O','X'});
    board.push_back({'X','O','X','X'});
    solve(board);
    int n=board.size();
    int m=board[0].size();
    show<char>(board);
    return 0;
}