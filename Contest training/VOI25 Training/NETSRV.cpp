#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
vector<int>adj[N+5];
int tin[N+5],tout[N+5],tim;
long long res;
void dfs(int u,int par) {
	tin[u]=++tim;
	for (auto v:adj[u]) {
		if (v!=par) dfs(v,u);
	}
	for (int i=0;i<(int)adj[u].size();i++) {
		if (adj[u][i]==par) {
			for (int j=i;j+1<(int)adj[u].size();j++) swap(adj[u][j],adj[u][j+1]);
			adj[u].pop_back();
			break;
		}
	}
	tout[u]=tim;
}
struct Line{
	int x,u,v;
	long long val;
	bool operator < (const Line &other) const {
		if (x!=other.x) return x<other.x;
		return val<other.val;
	}
};
vector<Line>line;
struct SegmentTree{
	long long st[N*4+5],lazy[N*4+5],inf=1e18;
	void down(int id) {
		long long t=lazy[id];
		lazy[id]=0;
		lazy[id*2]+=t,st[id*2]+=t;
		lazy[id*2+1]+=t,st[id*2+1]+=t;
	}
	void update(int id,int l,int r,int u,int v,long long val) {
		if (l>v||r<u) return;
		if (u<=l&&r<=v) {
			st[id]+=val;
			lazy[id]+=val;
			return;
		}
		down(id);
		int mid=(l+r)/2;
		update(id*2,l,mid,u,v,val);
		update(id*2+1,mid+1,r,u,v,val);
		st[id]=max(st[id*2],st[id*2+1]);
	}
} tree;
int main() {
	freopen("NETSRV.INP","r",stdin);
	freopen("NETSRV.OUT","w",stdout);
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
    for (int i=1;i<=m;i++) {
    	int u,v;
    	long long w;
    	cin>>u>>v>>w;
    	if (tin[u]>tin[v]) swap(u,v);
    	if (tout[u]<tin[v]) {
    		line.push_back({tin[u],tin[v],tout[v],w});
    		line.push_back({tout[u]+1,tin[v],tout[v],-w});
    	}
    	else {
    		int t = *lower_bound(adj[u].begin(), adj[u].end(), v, [](int i, int j)
	        {
	            return tout[i]<tout[j];
	        });
	        //cout<<u<<' '<<v<<' '<<tin[u]<<' '<<tout[u]<<' '<<tin[v]<<' '<<tout[v]<<' '<<t<<endl;
	        if (tin[t]-1>=1) {
	        	line.push_back({1,tin[v],tout[v],w});
	        	line.push_back({tin[t],tin[v],tout[v],-w});
	        }
	        if (tout[t]+1<=n) {
	            line.push_back({tin[v],tout[t]+1,n,w});
	            line.push_back({tout[v]+1,tout[t]+1,n,-w});
	        }
    	}
    }
    sort(line.begin(),line.end());
    for (auto temp:line) {
    	tree.update(1,1,n,temp.u,temp.v,temp.val);
    	//cout<<temp.x<<' '<<temp.u<<' '<<temp.v<<' '<<temp.val<<' '<<tree.st[1]<<endl;
    	res=max(res,tree.st[1]);
    }
    cout<<res;
}