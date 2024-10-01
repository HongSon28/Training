#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int sub,n,m;
vector<pair<int,int>>adj[N+5];
int low[N+5],num[N+5],tim;
bool vis[N+5];
long long sz[N+5],sum,mod=998244353;
long long res1[N+5],res2[N+5];
void dfs(int u,int par) {
	sz[u]=1;
	vis[u]=true;
	num[u]=low[u]=++tim;
	bool ispar=false;
	for (auto [v,id]:adj[u]) {
		if (v==par&&!ispar) {
			ispar=true;
			continue;
		}
		if (!num[v]) {
			dfs(v,u);
			sz[u]+=sz[v];
			low[u]=min(low[u],low[v]);
		} else low[u]=min(low[u],num[v]);
	}
}
void dfs2(int u,int par,int root) {
	vis[u]=true;
	vector<long long>cur;
	long long sum=sz[root]-1;
	bool ispar=false;
	for (auto [v,id]:adj[u]) {
		if (v==par&&!ispar) {
			ispar=true;
			continue;
		}
		if (!vis[v]) {
			dfs2(v,u,root);
			if (u==root||low[v]>=num[u]) {
				cur.push_back(sz[v]);
				sum-=sz[v];
			} 
		}
	}
	cur.push_back(sum);
	sum=cur[0];
	for (int i=1;i<(int)cur.size();i++) {
		res1[u]+=cur[i]*sum;
		sum+=cur[i];
		res1[u]%=mod;
		sum%=mod;
	}
	res1[u]-=n-sz[root];
}
void dfs3(int u,int par,int root) {
	vis[u]=true;
	bool ispar=false;
	for (auto [v,id]:adj[u]) {
		if (v==par&&!ispar) {
			ispar=true;
			continue;
		}
		if (!vis[v]) {
			dfs3(v,u,root);
			if (low[v]==num[v]) {
				//cout<<id<<' '<<sz[root]<<' '<<sz[v]<<endl;
				res2[id]=(sz[root]-sz[v])*sz[v];
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>sub>>n>>m;
    for (int i=1;i<=m;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back({v,i});
    	adj[v].push_back({u,i});
    }
    vector<long long>v;
    for (int i=1;i<=n;i++) {
    	if (!vis[i]) {
    		dfs(i,i);
    		v.push_back(sz[i]);
    		//cout<<sz[i]<<' ';
    	}
    }
    long long cur=v[0];
    for (int i=1;i<(int)v.size();i++) {
    	sum+=cur*v[i];
    	sum%=mod;
    	cur+=v[i];
    	cur%=mod;
    }
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=n;i++)
    	if (!vis[i]) dfs2(i,i,i);
    memset(vis,false,sizeof(vis));
    for (int i=1;i<=n;i++)
    	if (!vis[i]) dfs3(i,i,i);
    for (int i=1;i<=n;i++) cout<<(res1[i]+sum)%mod<<' ';
    cout<<'\n';
    for (int i=1;i<=m;i++) cout<<(res2[i]+sum)%mod<<' ';
}