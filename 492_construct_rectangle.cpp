#include<bits/stdc++.h>

using namespace std;

vector<int> constructRectangle(int area) {
    int W=sqrt(area);
    while(W>0){
        if(area%W==0){
            int L=area/W;
            vector<int> res;
            res.push_back(L);
            res.push_back(W);
            return res;
        }
        W--;
    }
}


int main(){

    return 0;
}