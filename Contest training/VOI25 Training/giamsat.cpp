#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int n,m;
vector<int>adj[N+5];
vector<pair<int,int>>edge;
int col[N+5],par[N+5];
int st,ed;
bool dfs(int u) {
	col[u]=1;
	for (auto v:adj[u]) {
		if (col[v]==0) {
			par[v]=u;
			if (dfs(v)) return true;
		} else if (col[v]==1) {
			st=u,ed=v;
			return true;
		}
	}
	col[u]=2;
	return false;
}
vector<int>vc;
int id[N+5],inf=1e9;
int calc(int u,int v) {
	if (id[u]==-1||id[v]==-1) return inf;
	if (id[u]>id[v]) return id[u]-id[v]+1;
	return id[u]+1+vc.size()-id[v];
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	edge.push_back({u,v});
    }
    st=ed=-1;
    for (int i=1;i<=n;i++) 
    	if (col[i]==0&&dfs(i)) break;
    if (st==-1) {
    	cout<<-1;
    	return 0;
    }
    vc.push_back(st);
    while (vc.back()!=ed) {
    	int t=vc.back();
    	t=par[t];
    	vc.push_back(t);
    }
    reverse(vc.begin(),vc.end());
    memset(id,-1,sizeof(id));
    for (int i=0;i<(int)vc.size();i++) id[vc[i]]=i;
    int mx=inf;
    int ru=-1,rv=-1;
    for (auto [u,v]:edge) {
    	int temp=calc(u,v);
    	if (mx>temp) {
    		mx=temp;
    		ru=u,rv=v;
    	}
    }
    if (ru==-1) cout<<-1;
    else {
    	cout<<mx<<'\n';
    	if (id[ru]>id[rv]) {
    		for (int i=id[rv];i<=id[ru];i++) cout<<vc[i]<<'\n';
    	} else {
    		for (int i=id[rv];i<(int)vc.size();i++) cout<<vc[i]<<'\n';
    		for (int i=0;i<=id[ru];i++) cout<<vc[i]<<'\n';
    	}
    }
}