#include<bits/stdc++.h>
using namespace std;
const int N=10000;
int n,m;
struct Edge{
	int u,v,w;
	bool operator < (const Edge &other) const {
		return w<other.w;
	}
};
vector<Edge>e;
int res;
int p[N+5];
int find_root(int u) {
	if (p[u]<0) return u;
	return p[u]=find_root(p[u]);
}
void Union(int u,int v) {
	if (p[u]>p[v]) swap(u,v);
	p[u]+=p[v];
	p[v]=u;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    memset(p,-1,sizeof(p));
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	e.push_back({u,v,w});
    }
    sort(e.begin(),e.end());
    for (auto [u,v,w]:e) {
    	int x=find_root(u),y=find_root(v);
    	if (x!=y) {
    		res+=w;
    		Union(x,y);
    	}
    }
    cout<<res;
}