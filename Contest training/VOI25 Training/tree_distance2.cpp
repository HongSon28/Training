#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k;
vector<int>adj[N+5];
long long res;
struct Deque{
	vector<long long>a;
	int size() {
		return a.size();
	}
	long long &operator [] (int id) {
		return a.rbegin()[id];
	}
	void push_front(int x) {
		a.push_back(x);
	}
	void clear() {
		vector<long long>().swap(a);
	}
	void sw(Deque &other) {
		swap(a,other.a);
	}
}f[N+5],s[N+5];
void dfs(int u,int par) {
	f[u].push_front(1);
	s[u].push_front(1);
	for (auto v:adj[u]) {
		if (v==par) continue;
		dfs(v,u);
		f[v].push_front(0);
		s[v].push_front(s[v][0]);
		if (f[v].size()>f[u].size()) {
			f[u].sw(f[v]);
			s[u].sw(s[v]);
		}
		for (int i=0;i<f[v].size();i++) {
			int x=max(0,k-i);
			if (x<f[u].size()) res+=s[u][x]*f[v][i];
		}
		long long cur=0;
		for (int i=f[v].size()-1;i>=0;i--) {
			f[u][i]+=f[v][i];
			cur+=f[v][i];
			s[u][i]+=cur;
		}
		f[v].clear();
		s[v].clear();
	}
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
    dfs(1,0);
    cout<<res;
}