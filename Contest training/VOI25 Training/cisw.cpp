#include<bits/stdc++.h>
//#include "cis.h"
using namespace std;
namespace personA {
	const int N=1e6;
	int n;
	vector<vector<int>>adj;
	int d[N+5];
	vector<int>cur;
	void initA(int _N, std::vector<pair<int, int>> _E, std::vector<int> _C) {
		n=_N;
		adj.resize(n+2);
		for (auto [u,v]:_E) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			d[u]++,d[v]++;
		}
		cur=_C;
	}
	bool del[N+5];
	int A2B(int b) {
		for (auto u:cur) 
			if (u==b) return -u;
		memset(del,false,sizeof(del));
		for (auto v:adj[b]) del[v]=true;
		vector<int>temp=cur;
		cur.clear();
		for (auto i:temp) if (!del[i]) cur.push_back(i);
		int u=0;
		for (auto i:cur) {
			if (d[i]>n/2) continue;
			if (u==0||d[u]>d[i]) u=i;
		}
		return u;
	}
}
namespace personB {
	const int N=1e6;
	int n;
	vector<vector<int>>adj;
	int d[N+5];
	vector<int>cur;
	void initB(int _N, std::vector<pair<int, int>> _E, std::vector<int> _I) {
		n=_N;
		adj.resize(n+2);
		for (auto [u,v]:_E) {
			adj[u].push_back(v);
			adj[v].push_back(u);
			d[u]++,d[v]++;
		}
		cur=_I;
	}
	bool del[N+5];
	int B2A(int a) {
		for (auto u:cur) 
			if (u==a) return -u;
		memset(del,false,sizeof(del));
		for (auto v:adj[a]) del[v]=true;
		vector<int>temp=cur;
		cur.clear();
		for (auto i:temp) if (del[i]) cur.push_back(i);
		int u=0;
		for (auto i:cur) {
			if (d[i]<n/2) continue;
			if (u==0||d[u]<d[i]) u=i;
		}
		return u;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
}