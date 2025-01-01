#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m,k;
int a[N+5][N+5];
int s[N+5][N+5];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int id[N+5][N+5];
struct Edge{
	int u,v,w;
	bool operator < (const Edge &other) const {
		return w<other.w;
	}
};
vector<Edge>ed;
int ans[N+5][N+5],inf=1e9+5;
long long res;
struct DSU{
	int p[N*N+5];
	vector<pair<int,int>>q[N*N+5];
	void init() {
		memset(p,-1,sizeof(p));
	}
	int find_root(int u) {
		if (p[u]<0) return u;
		return p[u]=find_root(p[u]);
	}
	void Union(int u,int v) {
		if (q[u].size()<q[v].size()) swap(u,v);
		p[u]+=p[v];
		p[v]=u;
		for (auto x:q[v]) q[u].push_back(x);
		q[v].clear();
	}
} dsu;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>a[i][j];
    		id[i][j]=(i-1)*m+j;
    		ans[i][j]=inf;
    	}
    }
    dsu.init();
    for (int i=1;i<=n;i++) {
    	for (int j=1;j<=m;j++) {
    		cin>>s[i][j];
    		if (s[i][j]) dsu.q[id[i][j]].push_back({i,j});
    		for (int t=0;t<4;t++) {
    			int x=i+dx[t],y=j+dy[t];
    			if (x>=1&&y>=1&&x<=n&&y<=m) {
    				ed.push_back({id[i][j],id[x][y],abs(a[i][j]-a[x][y])});
    			}
    		}
    	}
    }
	sort(ed.begin(),ed.end());
	for (auto [u,v,w]:ed) {
		int x=dsu.find_root(u),y=dsu.find_root(v);
		if (x==y) continue;
		if (-dsu.p[x]-dsu.p[y]>=k) {
			dsu.Union(x,y);
			int r=dsu.find_root(x);
			for (auto t:dsu.q[r]) ans[t.first][t.second]=w;
			dsu.q[r].clear();
		} else dsu.Union(x,y);
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]) res+=ans[i][j];
    cout<<res;
}