#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
vector<vector<long long>>adj(N+5);
long long timer,str[N+5],en[N+5],par[N+5];
long long res=0;
struct Segment{
    long long x,y1,y2,type;
    bool operator < (const Segment& other) const {
        if (x== other.x) return type<other.type;
        return x < other.x;
    }
};
vector<Segment>Segments;
void dfs(long long u,long long parent) {
    str[u]=++timer;
    for (auto v:adj[u]){
        if (v==parent) continue;
        par[v]=u;
        dfs(v,u);
    }
    en[u]=timer;
}
struct Node{
    long long lazy, val;
};
Node st[N*4+5];
void down(int id) {
    long long t=st[id].lazy;
    st[id].lazy=0;
    st[id*2].lazy+=t;
    st[id*2].val+=t;
    st[id*2+1].lazy+=t;
    st[id*2+1].val+=t;
}
void update(int id,int l,int r,int u,int v,long long val) {
    if (u>r||v<l) return;
    if (u<=l&&r<=v) {
        st[id].lazy+=val;
        st[id].val+=val;
        return;
    }
    int mid=(l+r)/2;
    down(id);
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id].val=max(st[id*2].val,st[id*2+1].val);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cin>>m;
    while (m--) {
        long long u,v,w;
        cin>>u>>v>>w;
        long long x1,x2,y1,y2;
        if (str[v]<=str[u]&&str[u]<=en[v]) swap(u,v);
        if (str[u]<=str[v]&&str[v]<=en[u]) {
            x1=str[v],x2=en[v];
            long long l,r;
            for (auto k:adj[u]) {
                if (k==par[u]) continue;
                if (str[k]<=str[v]&&str[v]<=en[k]) {
                    l=str[k];
                    r=en[k];
                    break;
                }
            }
            //cout<<u<<' '<<v<<' '<<l<<' '<<r<<endl;
            y1=1;
            y2=l-1;
            if (y1<=y2) {
                Segments.push_back({x1,y1,y2,w});
                Segments.push_back({x2+1,y1,y2,-w});
                Segments.push_back({y1,x1,x2,w});
                Segments.push_back({y2+1,x1,x2,-w});
                //cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
            }
            y1=r+1;
            y2=n;
            if (y1<=y2) {
                Segments.push_back({x1,y1,y2,w});
                Segments.push_back({x2+1,y1,y2,-w});
                Segments.push_back({y1,x1,x2,w});
                Segments.push_back({y2+1,x1,x2,-w});
                //cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
            }
        } else {
            x1=str[u];
            x2=en[u];
            y1=str[v];
            y2=en[v];
            Segments.push_back({x1,y1,y2,w});
            Segments.push_back({x2+1,y1,y2,-w});
            Segments.push_back({y1,x1,x2,w});
            Segments.push_back({y2+1,x1,x2,-w});
            //cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<endl;
        }
    }
    sort(Segments.begin(),Segments.end());
    for (int i=0;i<Segments.size();i++) {
        update(1,1,n,Segments[i].y1,Segments[i].y2,Segments[i].type);
        res=max(res,st[1].val);
    }
    cout<<res;
}
/*
5
1 2
1 3
2 4
2 5
5
1 3 10
2 5 6
1 2 5
2 3 5
2 4 5
*/
