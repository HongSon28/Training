#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
string s[N+5],t[N+5];
struct Trie{
	struct Node {
		int c[27];
		vector<int>id;
	};
	vector<Node>node;
	int n;
	void init_node(int i) {
		memset(node[i].c,-1,sizeof(node[i].c));
	}
	void init() {
		n=1;
		node.emplace_back();
		init_node(0);
	}
	void add_string(string s,int cid) {
		int cur=0;
		for (auto ch:s) {
			if (node[cur].c[ch-'A']==-1) {
				node[cur].c[ch-'A']=n;
				node.emplace_back();
				init_node(n);
				n++;
			}
			cur=node[cur].c[ch-'A'];
			node[cur].id.push_back(cid);
		} 
	}
	pair<int,int>get(string s) {
		int cur=0;
		for (auto ch:s) {
			if (node[cur].c[ch-'A']==-1) return {-1,-1};
			cur=node[cur].c[ch-'A'];
		}
		return {node[cur].id[0],node[cur].id.back()};
	}
	int get_res(string s,int l,int r) {
		int cur=0;
		for (auto ch:s) {
			if (node[cur].c[ch-'A']==-1) return 0;
			cur=node[cur].c[ch-'A'];
		}
		int lo=0,hi=node[cur].id.size()-1;
		int resl=-1,resr=-1;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (node[cur].id[mid]>=l) {
				resl=mid;
				hi=mid-1;
			} else lo=mid+1;
		}
		lo=0,hi=node[cur].id.size()-1;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (node[cur].id[mid]<=r) {
				resr=mid;
				lo=mid+1;
			} else hi=mid-1;
		}
		if (resl==-1||resr==-1||resl>resr) return 0;
		return resr-resl+1;
	}
} trie1,trie2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>s[i];
	sort(s+1,s+1+n);
	trie1.init(),trie2.init();
	for (int i=1;i<=n;i++) {
		t[i]=s[i];
    	reverse(t[i].begin(),t[i].end());
    	trie1.add_string(s[i],i);
    	trie2.add_string(t[i],i);
	}
	while (q--) {
		string s,t;
		cin>>s>>t;
		reverse(t.begin(),t.end());
		pair<int,int>p=trie1.get(s);
		if (p.first==-1) cout<<0<<'\n';
		else cout<<trie2.get_res(t,p.first,p.second)<<'\n';
	}
}