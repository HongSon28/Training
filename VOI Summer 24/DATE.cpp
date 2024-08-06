#include<bits/stdc++.h>
using namespace std;
const int N=3e5,LG=18;
int n,k;
vector<int>adj[N+5];
int h[N+5],curt,res,t[N+5],up[N+1][LG+1],cur;
void dfs(int u,int par) {
	t[u]=++curt;
	for (auto v:adj[u]) {
		if (v==par) continue;
		h[v]=h[u]+1;
		up[v][0]=u;
		for (int i=1;i<=LG;i++) up[v][i]=up[up[v][i-1]][i-1];
		dfs(v,u);
	}
}
int lca(int u,int v) {
	if (h[u]<h[v]) swap(u,v);
	int k=h[u]-h[v];
	for (int i=0;i<=LG;i++) {
		if (k>>i&1) u=up[u][i];
	}
	if (u==v) return u;
	k=__lg(h[u]);
	for (int i=k;i>=0;i--) {
		if (up[u][i]!=up[v][i]) {
			u=up[u][i];
			v=up[v][i];
		}
	}
	return up[u][0];
}
int d(int u,int v) {
	int k=lca(u,v);
	return h[u]+h[v]-2*h[k];
}
set<pair<int,int>>s;
bool check(int x) {
	pair<int,int>y={t[x],x};
	if (s.empty()) {
		s.insert(y);
		return true;
	}
	//cout<<(*s.begin()).second<<' '<<(*s.rbegin()).second<<' '<<t[x]<<endl;
	if (y<(*s.begin())||y>(*s.rbegin())) {
		int u=(*s.begin()).second,v=(*s.rbegin()).second;
		int temp=d(x,u)+d(x,v)-d(u,v);
		if (cur+temp<=2*k-2) {
			cur+=temp;
			s.insert(y);
			//cout<<x<<' '<<temp<<' '<<cur<<endl<<endl;
			return true;
		}
	} else {
		auto it2=s.lower_bound(y);
		auto it1=it2;
		it1--;
		int u=(*it1).second,v=(*it2).second;
		int temp=d(x,u)+d(x,v)-d(u,v);
		if (cur+temp<=2*k-2) {
			cur+=temp;
			s.insert(y);
			//cout<<x<<' '<<u<<' '<<v<<' '<<temp<<' '<<cur<<endl<<endl;
			return true;
		}
	}
	return false;
}
void del(int x) {
	pair<int,int>y={t[x],x};
	if (s.size()==1) {
		s.erase(s.lower_bound(y));
		cur=0;
		return;
	}
	int u,v;
	if (y==(*s.begin())) {
		auto it1=s.rbegin();
		auto it2=s.begin();
		it2++;
		u=(*it1).second,v=(*it2).second;
	} else if (y==(*s.rbegin())) {
		auto it1=s.end();
		it1--;it1--;
		auto it2=s.begin();
		u=(*it1).second,v=(*it2).second;
	} else {
		auto it2=s.lower_bound(y);
		auto it1=it2;
		it1--;
		it2++;
		u=(*it1).second,v=(*it2).second;
	}
	int temp=d(x,u)+d(x,v)-d(u,v);
	cur-=temp;
	s.erase(s.lower_bound(y));
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
	dfs(0,-1);
	//for (int i=0;i<n;i++) cout<<t[i]<<' ';
	//cout<<endl;
	int r=0;
	s.insert({t[0],0});
	for (int l=0;l<n;l++) {
		while (r+1<n&&check(r+1)) r++;
		res=max(res,r-l+1);
		//cout<<l<<' '<<r<<endl;
		del(l);
	}
	cout<<res;
}