#include<bits/stdc++.h>
using namespace std;

double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
    int n=quality.size();
    vector<pair<double,int> > rate(n);
    for(int i=0;i<n;i++){
        rate[i]=make_pair(((double)wage[i])/quality[i],quality[i]);
    }
    sort(rate.begin(),rate.end());
    priority_queue<int> heap;
    int sum=0;
    double res;
    for(int i=0;i<K;i++){
        sum+=rate[i].second;
        heap.push(rate[i].second);
    }
    res=sum*rate[K-1].first;
    for(int i=K;i<n;i++){
        if(rate[i].second < heap.top()){
            sum=sum-heap.top()+rate[i].second;
            double tmp=rate[i].first*sum;
            if(res>tmp){
                res=tmp;
            }
            heap.pop();
            heap.push(rate[i].second);
        }
    }
    return res;
}

int main(){
    int a[] = {14,56,59,89,39,26,86,76,3,36};
    int b[] = {90,217,301,202,294,445,473,245,415,487};
    int K=2;
    vector<int> quality;
    vector<int> wage;
    for(int i=0;i<10;i++){
        quality.push_back(a[i]);
        wage.push_back(b[i]);
    }
    cout<<mincostToHireWorkers(quality,wage,K)<<endl;
    return 0;
}