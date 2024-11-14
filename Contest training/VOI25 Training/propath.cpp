#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long c[N+5];
vector<int>adj[N+5];
int cnt[N+5];
bool del[N+5];
long long res;
void countchild(int u,int par) {
	cnt[u]=1;
	for (auto v:adj[u]) {
		if (v==par||del[v]) continue;
		countchild(v,u);
		cnt[u]+=cnt[v];
	}
}
int centroid(int u,int par,int n) {
	for (auto v:adj[u]) {
		if (v!=par&&!del[v]&&cnt[v]>n/2) return centroid(v,u,n);
	}
	return u;
}
struct dat{
	int u,dist,p;
	bool operator < (const dat &other) const {
		return c[u]>c[other.u];
	}
};
vector<dat>cur;
void dfs(int u,int par,int dist,int p) {
	cur.push_back({u,dist,p});
	for (auto v:adj[u]) {
		if (v==par||del[v]) continue;
		if (p==-1) dfs(v,u,dist+1,v);
		else dfs(v,u,dist+1,p);
	}
}
void update(int u) {
	cur.clear();
	dfs(u,0,0,-1);
	sort(cur.begin(),cur.end());
	//cout<<u<<endl;
	int mx1=0,mx2=-1;
	for (int i=1;i<(int)cur.size();i++) {
		//cout<<cur[i].u<<' '<<cur[mx1].u<<' '<<cur[mx2].u<<endl;
		if (cur[mx1].p!=cur[i].p) res=max(res,c[cur[i].u]*(cur[i].dist+cur[mx1].dist));
		else if (mx2!=-1) res=max(res,c[cur[i].u]*(cur[i].dist+cur[mx2].dist));
		if (mx2==-1) {
			if (cur[mx1].p!=cur[i].p) mx2=i;
			else if (cur[mx1].dist<cur[i].dist) mx1=i;
		} else if (cur[mx2].p==cur[i].p||cur[mx1].p==cur[i].p) {
			if (cur[mx2].p==cur[i].p) { 
				if (cur[mx2].dist<cur[i].dist) mx2=i;
			} else { 
				if (cur[mx1].dist<cur[i].dist) mx1=i;
			}
		} else {
			if (cur[mx2].dist<cur[i].dist) mx2=i;
		}
		if (mx2!=-1&&cur[mx1].dist<cur[mx2].dist) swap(mx1,mx2);
	}
	//cout<<u<<' '<<res<<endl;
}
void solve(int u) {
	countchild(u,0);
	int cur=cnt[u],root=centroid(u,0,cur);
	//cout<<u<<' '<<cur<<' '<<root<<endl;
	update(root);
	del[root]=true;
	for (auto v:adj[root]) {
		if (!del[v]) solve(v);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<n;i++) {
    	int u,v;
    	cin>>u>>v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    solve(1);
    cout<<res;
}