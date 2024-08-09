#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
string s;
int n;
vector<vector<int>>adj(N+5);
int in[N+5],a[N+5];
long long res;
void dfs(int u) {
	for (auto v:adj[u]) {
		if (a[v]<=a[u]) {
			a[v]=a[u]+1;
			dfs(v);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    for (int i=1;i<(int)s.size();i++) {
    	if (s[i]=='<') {
    		adj[i].push_back(i+1);
    		in[i+1]++;
    	} else {
    		adj[i+1].push_back(i);
    		in[i]++;
    	}
    }
    for (int i=1;i<=n+1;i++) {
    	if (!in[i]) dfs(i);
    }
    for (int i=1;i<=n+1;i++) res+=a[i];
    cout<<res;
}