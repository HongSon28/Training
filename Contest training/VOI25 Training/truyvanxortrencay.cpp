#include<bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
const int N=5e4,SQ=223;
int n,q;
vector<pair<int,int>>adj[N+5];
int a[N+5];
void dfs(int u,int par) {
	for (auto [v,w]:adj[u]) {
		if (v==par) continue;
		a[v]=(a[u]^w);
		dfs(v,u);
	}
}
struct Trie{
	int n;
	struct Node{
		int c[2];
		int cnt;
	};
	Node v[N*100+5];
	void init_node(int id) {
		v[id].cnt=0;
		v[id].c[0]=v[id].c[1]=-1;
	}
	void init() {
		n=1;
		init_node(0);
	}
	void add(int x) {
		int pos=0;
		for (int i=30;i>=0;i--) {
			int cur=((x>>i)&1);
			if (v[pos].c[cur]==-1) {
				init_node(n);
				v[pos].c[cur]=n;
				n++;
			} 
			pos=v[pos].c[cur];
			v[pos].cnt++;
		}
	}
	void del(int x) {
		int pos=0;
		for (int i=30;i>=0;i--) {
			int cur=((x>>i)&1);
			pos=v[pos].c[cur];
			v[pos].cnt--;
		}
	}
	int get(int x) {
		int pos=0,ans=0;
		for (int i=30;i>=0;i--) {
			int cur=((x>>i)&1);
			if (cur==0) {
				if (v[pos].c[1]!=-1&&v[v[pos].c[1]].cnt) {
					ans|=(1<<i);
					pos=v[pos].c[1];
				} else pos=v[pos].c[0];
			} else {
				if (v[pos].c[0]!=-1&&v[v[pos].c[0]].cnt) pos=v[pos].c[0];
				else {
					ans|=(1<<i);
					pos=v[pos].c[1];
				}
			}
			//cout<<i<<' '<<cur<<' '<<pos<<endl;
		}
		return (ans^x);
	}
} trie;
int qu[N+5];
bool used[N+5],ex[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<n;i++) {
    	int u,v,w;
    	cin>>u>>v>>w;
    	adj[u].push_back({v,w});
    	adj[v].push_back({u,w});
    }
    dfs(1,0);
    trie.init();
    for (int i=1;i<=q;i++) cin>>qu[i];
    for (int l=1;l<=q;l+=SQ) {
    	int res=0;
    	int r=min(l+SQ-1,q);
    	vector<int>cur;
    	for (int i=1;i<=n;i++) ex[i]=false;
    	for (int i=l;i<=r;i++) {
    		cur.push_back(qu[i]);
    		ex[qu[i]]=true;
    	}
    	sort(cur.begin(),cur.end());
    	cur.resize(unique(cur.begin(),cur.end())-cur.begin());
    	for (auto x:cur) {
    		if (used[x]) {
    			trie.del(a[x]);
    		}
    	}
    	for (int i=1;i<=n;i++) {
    		if (used[i]&&!ex[i]) res=max(res,trie.get(a[i]));
    	}
    	for (int i=l;i<=r;i++) {
    		int mx=res;
    		used[qu[i]]=1-used[qu[i]];
    		for (auto x:cur) {
    			if (used[x]) {
    				trie.add(a[x]);
    				//cout<<i<<' '<<x<<endl;
    				mx=max(mx,trie.get(a[x]));
    			}
    		}
    		cout<<mx<<'\n';
    		for (auto x:cur) {
    			if (used[x]) trie.del(a[x]);
    		}
    	}
    	for (auto x:cur) {
    		if (used[x]) trie.add(a[x]);
    	}
    }
}