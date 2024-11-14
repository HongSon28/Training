#include<bits/stdc++.h>
using namespace std;
const int N=2e5,SZ=447;
int n,k;
vector<int>adj[N+5];
int p[N+5],r[N+5];
vector<int>euler;
int fai[N+5],d[N+5],rmq[N*2+5][20];
int cur;
void dfs(int u,int par) {
	d[u]=d[par]+1;
	cur++;
	euler.push_back(u);
	if (fai[u]==0) fai[u]=cur;
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		cur++;
		euler.push_back(u);
	}
}
void prep() {
	for (int i=1;i<=cur;i++) rmq[i][0]=euler[i];
	for (int j=1;(1<<j)<=cur;j++) {
		for (int i=1;i+(1<<j)-1<=cur;i++) {
			if (d[rmq[i][j-1]]<d[rmq[i+(1<<(j-1))][j-1]]) rmq[i][j]=rmq[i][j-1];
			else rmq[i][j]=rmq[i+(1<<(j-1))][j-1];
		}
	}
}
int lca(int u,int v) {
	int lg=__lg(v-u+1);
	if (d[rmq[u][lg]]<d[rmq[v-(1<<lg)+1][lg]]) return rmq[u][lg];
	return rmq[v-(1<<lg)+1][lg];
}
int dist(int u,int v) {
	if (fai[u]>fai[v]) swap(u,v);
	int k=lca(fai[u],fai[v]);
	//cout<<u<<' '<<v<<' '<<k<<' '<<d[u]<<' '<<d[v]<<' '<<d[k]<<endl;
	return d[u]+d[v]-2*d[k];
}
vector<int>added;
int res[N+5];
queue<int>q[N+5];
bool vis[N+5],used[N+5];
void bfs(int L,int R) {
	for (int i=1;i<=n;i++) vis[i]=false;
	for (int i=L;i<=R;i++) {
		q[n-r[i]].push(p[i]);
		vis[p[i]]=true;
		if (!used[p[i]]) {
			added.push_back(p[i]);
			used[p[i]]=true;
		}
	}
	for (int i=0;i<=n;i++) {
		while (!q[i].empty()) {
			int u=q[i].front();
			//cout<<i<<' '<<u<<endl;
			q[i].pop();
			if (i==n) continue;
			for (auto v:adj[u]) {
				if (!vis[v]) {
					vis[v]=true;
					if (!used[v]) {
						added.push_back(v);
						used[v]=true;
					}
					q[i+1].push(v);
				}
			}
		}
	}
}
void solve(int L,int R) {
	R=min(R,k);
	added.clear();
	//cout<<L<<' '<<R<<endl;
	bfs(L,R);
	for (auto x:added) {
		//cout<<x<<endl;
		for (int i=L;i<=R;i++) {
			//cout<<p[i]<<' '<<dist(x,p[i])<<endl;
			if (dist(x,p[i])<=r[i]) {
				res[i]++;
				break;
			}
		}
	}
	//cout<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }	
    for (int i=1;i<=k;i++) {
    	cin>>p[i]>>r[i];
    	r[i]=min(r[i],n);
    }
    euler.push_back(0);
    dfs(1,0);
    prep();
    for (int i=1;i<=k;i+=SZ) solve(i,i+SZ-1);
    for (int i=1;i<=k;i++) {
    	if (i!=1) res[i]+=res[i-1];
    	cout<<res[i]<<'\n';
    }
}