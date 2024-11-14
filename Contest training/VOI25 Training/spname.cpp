#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=2e5;
int n;
string s[N+5],t[N+5];
long long res;
struct Trie{
	int n,sz;
	long long mx;
	struct Node{
		int c[26];
		int depth;
		long long cnt;
		vector<int>v;
	};
	vector<int>lst;
	vector<Node>trie;
	void init_node(int id,int par) {
		trie[id].cnt=0;
		memset(trie[id].c,-1,sizeof(trie[id].c));
		if (id!=0) trie[id].depth=trie[par].depth+1;
		else trie[id].depth=0;
	}
	void init() {
		n=1;
		mx=0;
		trie.resize(1);
		init_node(0,0);
	}
	void del() {
		trie.clear();
	}
	void add_string(const int &id,const string &s) {
		int cur=0;
		sz++;
		lst.push_back(id);
		for (auto i:s) {
			if (trie[cur].c[i-'a']==-1) {
				trie.emplace_back();
				trie[cur].c[i-'a']=n;
				init_node(n,cur);
				n++;
			}
			cur=trie[cur].c[i-'a'];
			trie[cur].cnt++;
			if (trie[cur].cnt>1) 
				mx=max(mx,trie[cur].cnt*trie[cur].depth);
		}
		trie[cur].v.push_back(id);
	}
} tree[N+5];
int id[N+5];
void dfs(int u) {
	id[u]=u+1;
	tree[id[u]].init();
	for (auto i:tree[0].trie[u].v) tree[id[u]].add_string(i,t[i]);
	for (int i=0;i<26;i++) {
		if (tree[0].trie[u].c[i]!=-1) {
			int v=tree[0].trie[u].c[i];
			dfs(v);
			if (tree[id[u]].sz<tree[id[v]].sz) swap(id[u],id[v]);
			for (auto i:tree[id[v]].lst) tree[id[u]].add_string(i,t[i]);
			tree[id[v]].del();
		}
	}
	/*
	cout<<u<<' '<<tree[0].trie[u].depth<<' '<<tree[id[u]].mx<<endl;
	for (auto i:tree[0].trie[u].v1) cout<<s[i]<<endl;
	cout<<endl;*/
	res=max(res,tree[id[u]].mx*tree[0].trie[u].depth);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    tree[0].init();
    for (int i=1;i<=n;i++) {
    	cin>>s[i];
    	t[i]=s[i];
    	reverse(t[i].begin(),t[i].end());
    	tree[0].add_string(i,s[i]);
    }
    dfs(0);
    cout<<res;
}