#include<bits/stdc++.h>
using namespace std;
const int N=300;
int n;
int w[N+5],p[N+5][N+5],d[N+5];
int inf=1e9,res;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>w[i];
        d[i]=w[i];
        pq.push({w[i],i});
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>p[i][j];
    while (!pq.empty()) {
        int du=pq.top().first;
        int u=pq.top().second;
        pq.pop();
        //cout<<u<<' '<<du<<' '<<d[u]<<endl;
        if (du!=d[u]) continue;
        res+=du;
        d[u]=-inf;
        for (int v=1;v<=n;v++) {
            if (v==u) continue;
            int w=p[u][v];
            if (d[v]>w) {
                d[v]=w;
                pq.push({d[v],v});
            }
        }
    }
    cout<<res;
}
