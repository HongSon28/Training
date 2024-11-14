#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,q,inf=1e9;
vector<pair<int,int>>adj[N+5];
int a[N+5];
struct query{
	int type,u,v;
} qu[N+5];
int t[N+5];
int d[N+5];
int res[N+5];
void dfs(int u,int par) {
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		d[v]=d[u]+1;
		a[v]=(a[u]^w);
		dfs(v,u);
	}
}
struct Trie{
	int n;
	struct Node{
		int c[2];
		int mn;
	};
	vector<int>lst;
	vector<Node>trie;
	void init_node(int id) {
		trie[id].mn=inf;
		memset(trie[id].c,-1,sizeof(trie[id].c));
	}
	void init() {
		n=1;
		trie.resize(1);
		init_node(0);
	}
	void del() {
		trie.clear();
		lst.clear();
	}
	void add(int id) {
		int cur=0;
		lst.push_back(id);
		for (int i=30;i>=0;i--) {
			int tmp=(a[id]>>i&1);
			if (trie[cur].c[tmp]==-1) {
				trie.emplace_back();
				trie[cur].c[tmp]=n;
				init_node(n);
				n++;
			}
			cur=trie[cur].c[tmp];
			trie[cur].mn=min(trie[cur].mn,t[id]);
		}
	}
	int walk(int v,int tim) {
		int cur=0,ans=0;
		for (int i=30;i>=0;i--) {
			int nxt;
			if (v>>i&1) {
				if (trie[cur].c[0]!=-1) {
					int temp=trie[cur].c[0];
					if (trie[temp].mn<=tim) nxt=temp;
					else {
						nxt=trie[cur].c[1];
						ans+=(1<<i);
					}
				} else {
					nxt=trie[cur].c[1];
					ans+=(1<<i);
				}
			} else {
				if (trie[cur].c[1]!=-1) {
					int temp=trie[cur].c[1];
					if (trie[temp].mn<=tim) {
						nxt=temp;
						ans+=(1<<i);
					} else nxt=trie[cur].c[0];
				} else nxt=trie[cur].c[0];
			}
			cur=nxt;
			//cout<<v<<' '<<cur<<' '<<ans<<endl;
		}
		return ans;
	}
} tree[N+5];
vector<int>queries[N+5];
int id[N+5];
void dfs2(int u,int par) {
	id[u]=u;
	tree[id[u]].init();
	tree[id[u]].add(u);
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		dfs2(v,u);
		if (tree[id[u]].lst.size()<tree[id[v]].lst.size()) swap(id[u],id[v]);
		for (auto i:tree[id[v]].lst) {
			tree[id[u]].add(i);
			//cout<<u<<' '<<v<<' '<<i<<endl;
		}
		tree[id[v]].del();
	}
	for (auto i:queries[u]) {
		res[i]=tree[id[u]].walk(a[qu[i].u],i);
		res[i]^=a[qu[i].u];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    t[1]=0;
    n=1;	
    cin>>q;
    for (int i=1;i<=q;i++) {
    	string temp;
    	cin>>temp>>qu[i].u>>qu[i].v;
    	if (temp=="Add") {
    		qu[i].type=1;
    		n++;
    		adj[qu[i].u].push_back({n,qu[i].v});
    		adj[n].push_back({qu[i].u,qu[i].v});
    		t[n]=i;
    	}
    	else {
    		qu[i].type=2;
    		queries[qu[i].v].push_back(i);
    	}
    }
    d[1]=1;
    dfs(1,0);
    //for (int i=1;i<=n;i++) cout<<a[i]<<' ';
    //cout<<endl;
    dfs2(1,0);
    for (int i=1;i<=q;i++) {
    	if (qu[i].type==2) cout<<res[i]<<'\n';
    }
}