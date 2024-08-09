#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int u,k;
vector<vector<int>>v(N+5);
void seive() {
    for (int i=1;i<=N;i++) {
        for (int j=i;j<=N;j+=i) v[j].push_back(i);
    }
}
int main() {
    seive();
    int m;
    cin>>m;
    while (m--){
        cin>>u>>k;
        if (v[u].size()<k) cout<<-1<<endl;
        else cout<<v[u][k-1]<<endl;
    }
}
