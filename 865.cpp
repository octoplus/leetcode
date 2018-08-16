#include<bits/stdc++.h>

using namespace std;

/*
 * bfs比较经典的题
 * 最开始的思路是每个状态都保存各自的数组，就像之前下棋一样
 * 看了别人的思路后发现不用
 * 只需要在每个位置用一个数组表示不同状态是否到达过，相同的状态不能到达相同的地方两次
 * 说明之前的题的解法也有改进的空间
 */

struct State{
    int x,y; //网格上的位置
    int s; //当前状态，拿到了多少钥匙
    int step;//已走的步数

    State(int x,int y,int s,int step):x(x),y(y),s(s),step(step){}
};

bool stepable(vector<string>& grid,vector<vector<vector<bool> > > &f,int next_x,int next_y,int n,int m, int s){
    if(!(next_x>=0 && next_x<n && next_y>=0 && next_y<m)) return 0;//超出网格范围
    char c=grid[next_x][next_y];
    if(c=='#') return 0; //是墙壁
    if(f[next_x][next_y][s]) return 0; //在相同状态下走过了
    if(c>='A'&&c<='F'&& ((1<<(tolower(c)-'a'))&s) ==0) return 0; //还未拿到相应的钥匙
    return 1;
}

int shortestPathAllKeys(vector<string>& grid) {
    int start_x=0,start_y=0;
    int cnt=0;
    int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='@'){
                start_x=i;
                start_y=j;
            }else if(grid[i][j]>='a' && grid[i][j]<='f')
                cnt++;
        }
    }
    
    int aim=(1<<(cnt))-1;
    int K=1<<cnt; //可能的状态数
    vector<vector<vector<bool> > > f(n); //非常关键，三维数组表示网格上各个点是否以某种状态经历过
    for(int i=0;i<n;i++){
        vector<vector<bool> > tmp(m);
        for(int j=0;j<m;j++){
            tmp[j]=vector<bool>(K,0);
        }
        f[i]=tmp;
    }
    pair<int,int> dxy[] = {make_pair(1,0),make_pair(0,1),make_pair(-1,0),make_pair(0,-1)};

    queue<State*> q;
    q.push(new State(start_x,start_y,0,0));

    while(!q.empty()){
        State* tmp=q.front();
        q.pop();
        // cout<<tmp->step<<endl;
        for(auto p:dxy){
            int next_x=tmp->x+p.first;
            int next_y=tmp->y+p.second;
            int s=tmp->s;
            if(stepable(grid,f,next_x,next_y,n,m,s)){
                char c=grid[next_x][next_y];
                if(c>='a'&&c<='f'){
                    s|=(1<<(c-'a'));
                }
                if(s==aim) return tmp->step+1;
                f[next_x][next_y][s]=1;
                State *next_s=new State(next_x,next_y,s,tmp->step+1);
                q.push(next_s);
            }
        }
        delete tmp;
    }
    return -1;
}

int main(){
    vector<string> grid {"@.a.#","###.#","b.A.B"};
    // vector<string> grid {"@..aA","..B#.","....b"};
    // vector<string> grid {"..#....##.","....d.#.D#","#...#.c...","..##.#..a.","...#....##","#....b....",".#..#.....","..........",".#..##..A.",".B..C.#..@"};
    cout<<shortestPathAllKeys(grid)<<endl;
    return 0;
}