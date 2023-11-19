#include<bits/stdc++.h>
using namespace std;
const int N=500;
int p,n,c;
double mn=1e9;
int res;
int d[N+5];
vector<int>spot;
vector<vector<pair<int,int>>>adj(N+5);
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
void dijkstra (int s) {
    for (int i=1;i<=p;i++) d[i]=1e9;
    d[s]=0;
    pq.push({0,s});
    while (!pq.empty()) {
        pair<int,int>t=pq.top();
        int du=t.first,u=t.second;
        pq.pop();
        if (du!=d[u]) continue;
        for (auto i:adj[u]) {
            int v=i.first,f=i.second;
            if (d[u]+f<d[v]) {
                d[v]=d[u]+f;
                pq.push({d[v],v});
            }
        }
    }
}
int main() {
    cin>>p>>n>>c;
    for (int i=1;i<=n;i++) {
        int t;
        cin>>t;
        spot.push_back(t);
    }
    for (int i=1;i<=c;i++) {
        int a,b,f;
        cin>>a>>b>>f;
        adj[a].push_back({b,f});
        adj[b].push_back({a,f});
    }
    for (int i=1;i<=p;i++) {
        dijkstra(i);
        int sum=0;
        for (auto j:spot) sum+=d[j];
        double t=(double)sum/(double)n;
        if (t<mn) {
            mn=t;
            res=i;
        }
    }
    cout<<res;
}
