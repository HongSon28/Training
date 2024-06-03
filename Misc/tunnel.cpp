#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
const ll inf=N*1e9;
ll n,m,x,y,l=1,r=1e9,res;
ll d[N+5],tr[N+4];
vector<int>v;
struct vwh{
    ll v,w,h;
};
vector<vwh>adj[N+4];
bool check(ll u, ll v, ll w){
	//cout<<u<<' '<<d[u]<<' '<<v<<' '<<d[v]<<' '<<w<<endl;
    if(d[v]>d[u]+w){
        d[v]=d[u]+w;
        return true;
    } return false;
}
struct uutien{
    ll vertex,dlab;
    bool operator < (const uutien& other) const{
        return other.dlab < dlab;
    }
};
priority_queue<uutien>pq;
void dij(ll mx){
     for(int i=1;i<=n;i++) d[i]=inf;
     d[x]=0;
     pq.push({x,0});
     while(!pq.empty()){
        uutien x=pq.top();
        pq.pop();
        ll u=x.vertex;
        if(x.dlab!=d[u]) continue;
        for(vwh i:adj[u]){
            if(i.h<mx) continue;
            if(check(u,i.v,i.w)){
                pq.push({i.v,d[i.v]});
            }
        }
    }
}
void trace(ll res) {
     for(int i=1;i<=n;i++) d[i]=inf;
     d[x]=0;
     pq.push({x,0});
     while(!pq.empty()){
        uutien x=pq.top();
        pq.pop();
        ll u=x.vertex;
        if(x.dlab!=d[u]) continue;
        for(vwh i:adj[u]){
            if(i.h<res) continue;
            if(check(u,i.v,i.w)){
                tr[i.v]=u;
                pq.push({i.v,d[i.v]});
            }
        }
    }
    while(y!=x){
        v.push_back(y);
        y=tr[y];
    }
    v.push_back(y);
    reverse(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(auto i:v) cout<<i<<' ';
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    cin>>n>>m>>x>>y;
    while(m--){
        ll u,v,w,h; cin>>u>>v>>w>>h;
        adj[u].push_back({v,h,w});
        adj[v].push_back({u,h,w});
    }
    while(l<=r){
        ll mid=(l+r)/2;
        dij(mid);
        if(d[y]!=inf){
            res=mid;
            l=mid+1;
        } else r=mid-1;
    }
    trace(res);
}