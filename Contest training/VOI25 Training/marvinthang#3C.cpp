#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e6;
int n;
string s[N+5];
struct Trie{
	int n;
	struct Node{
		int c[26];
		bool ed;
	};
	vector<vector<int>>adj;
	vector<Node>v;
	void init_node(int id,int par) {
		memset(v[id].c,-1,sizeof(v[id].c));
		adj.emplace_back();
		v[id].ed=false;
		if (par!=-1) adj[par].push_back(id);
	}
	void init() {
		v.emplace_back();
		init_node(0,-1);
		n=1;
	}
	void add(int id) {
		int cur=0;
		for (int i=s[id].size()-1;i>=0;i--) {
			char ch=s[id][i];
			if (v[cur].c[ch-'a']==-1) {
				v.emplace_back();
				init_node(n,cur);
				v[cur].c[ch-'a']=n;
				n++;
			}
			cur=v[cur].c[ch-'a'];
		}
		v[cur].ed=true;
	}
} trie; 
int f[M+5],cnt[M+5],res=1;
void dfs(int u) {
	//cout<<u<<' '<<trie.v[u].ed<<endl;
	for (auto s:trie.adj[u]) {
		dfs(s);
		if (trie.v[s].ed) cnt[u]++;
	}
	if (trie.v[u].ed) f[u]=1;
	for (auto s:trie.adj[u]) {
		if (trie.v[u].ed) {
			if (trie.v[s].ed) res=max(res,f[s]+cnt[u]);
			f[u]=max(f[u],f[s]+cnt[u]);
		} else if (trie.v[s].ed) res=max(res,f[s]+cnt[u]-1);
	}
	for (auto s:trie.adj[u]) {
		if (!trie.v[s].ed) continue;
		for (auto t:trie.adj[u]) {
			if (s==t||!trie.v[t].ed) continue;
			res=max(res,f[s]+f[t]+cnt[u]-2+trie.v[u].ed);
		}
	}
	//cout<<u<<' '<<f[u]<<' '<<res<<endl;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n;
	trie.init();
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		trie.add(i);
	}
	dfs(0);
	cout<<res;
}