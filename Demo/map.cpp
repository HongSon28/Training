
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxN = 1e5 + 5;
const ll maxW = 1e9 + 5;
const ll inf=maxN*maxW;
ll n,m;
ll d[maxN],f[maxN];
struct vw{
    ll v,w,t;
};
vector<vector<vw>>vt(maxN);
struct uutien{
    ll vertex, dlab, t;
    bool operator < (const uutien& other) const{
        return other.dlab < dlab;
    }
};
void dij(){
    priority_queue<uutien>pq;
    pq.push({1,0,0});
    while(!pq.empty()){
        uutien u=pq.top();
        pq.pop();
        ll x=u.vertex;
        if(d[x]!=u.dlab) continue;
        for(auto i: vt[x]){
            if(d[i.v]>d[x]+i.w+i.t*u.t){
                d[i.v]=d[x]+i.w+i.t*u.t;
                //cout<<i.v<<' '<<d[i.v]<<endl;
                pq.push({i.v,d[i.v],u.t+1});
            }
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("MAP.INP","r",stdin);
	freopen("MAP.OUT","w",stdout);
	cin>>n>>m;
	while(m--){
        ll u,v,w,t;
        cin>>u>>v>>w>>t;
        vt[u].push_back({v,w,t});
        vt[v].push_back({u,w,t});
	}
	for(int i=2;i<=n;i++) d[i]=inf;
	d[1]=0;
	dij();
	cout<<(d[n] == inf ? -1 : d[n]);
}
