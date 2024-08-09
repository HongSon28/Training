#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
pair<long long,long long>p[N+5];
long long res;
vector<vector<int>>adj(N+5);
struct dat{
    long long u,d;
    bool operator < (const dat &other) const{
        return d>other.d;
    }
};
long long d[N+5],inf=1e18;
priority_queue<dat>pq;
void dij() {
    for (int i=2;i<=N;i++) d[i]=inf;
    pq.push({1,0});
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        long long u=t.u,du=t.d;
        if (d[u]!=du) continue;
        for (auto v:adj[u]) {
            long long w=p[v].first-p[u].first-p[u].second;
            w=max(w,0ll);
            if (du+w<d[v]) {
                d[v]=du+w;
                pq.push({v,d[v]});
            }
        }
    }
    res+=d[n];
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>p[i].first>>p[i].second;
        res+=p[i].second;
    }
    sort(p+1,p+1+n);
    for (int i=1;i<=n;i++) {
        int lo=i,hi=n,j=i;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (p[mid].first-p[i].first-p[i].second<=0) {
                j=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        adj[i].push_back(j);
        if (i!=1) adj[i].push_back(i-1);
        if (j!=n) adj[i].push_back(j+1);
    }
    dij();
    cout<<res;
}
