#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,q;
string s[N+5],t[N+5];
vector<string>vs[2];
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
			if (node[cur].c[ch-'a']==-1) {
				node[cur].c[ch-'a']=n;
				node.emplace_back();
				init_node(n);
				n++;
			}
			cur=node[cur].c[ch-'a'];
			node[cur].id.push_back(cid);
		}
	}
	void walk(int id,int l,int r,int vid,string cur) {
		if (id!=0) vs[vid].push_back(cur);
		for (char ch='a';ch<='z';ch++) {
			if (node[id].c[ch-'a']==-1) continue;
			int nxt=node[id].c[ch-'a'];
			int ans=-1,lo=0,hi=node[nxt].id.size()-1;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (node[nxt].id[mid]>=l) {
					ans=node[nxt].id[mid];
					hi=mid-1;
				} else lo=mid+1;
			}
			if (ans==-1||ans>r) continue;
			walk(nxt,l,r,vid,cur+ch);
		}
	}
} trie1,trie2;
namespace sub1{
	void solve() {
		trie1.init(),trie2.init();
		for (int i=1;i<=n;i++) {
			t[i]=s[i];
			reverse(t[i].begin(),t[i].end());
			trie1.add_string(s[i],i);
			trie2.add_string(t[i],i);
		}
		while (q--) {
			vs[0].clear(),vs[1].clear();
			int l,r;
			cin>>l>>r;
			trie1.walk(0,l,r,0,"");
			trie2.walk(0,l,r,1,"");
			vector<string>cur;
			for (int i=0;i<(int)vs[1].size();i++) reverse(vs[1][i].begin(),vs[1][i].end());
			for (auto pre:vs[0]) {
				for (auto suf:vs[1]) cur.push_back(pre+suf);
			}
			long long res=1;
			sort(cur.begin(),cur.end());
			for (int i=1;i<(int)cur.size();i++) res+=(cur[i]!=cur[i-1]);
			cout<<res<<'\n';
		}
	}
}
namespace sub3{
	bool check() {
		for (int i=1;i<=n;i++) {
			for (int j=1;j<(int)s[i].size();j++) if (s[i][j]!=s[i][j-1]) return false;
		}
		return true;
	}
	const int LG=19;
	int rmq[26][N+1][LG+1],mx[26];
	void solve() {
		for (int i=1;i<=n;i++) rmq[s[i][0]-'a'][i][0]=s[i].size();
		for (int c=0;c<26;c++) {
			for (int i=1;(1<<i)<=n;i++) {
				for (int j=1;j+(1<<i)-1<=n;j++) rmq[c][j][i]=max(rmq[c][j][i-1],rmq[c][j+(1<<(i-1))][i-1]);
			}
		}
		while (q--) {
			int l,r;
			cin>>l>>r;
			int lg=__lg(r-l+1);
			for (int c=0;c<26;c++) mx[c]=max(rmq[c][l][lg],rmq[c][r-(1<<lg)+1][lg]);
			long long res=0;
			for (int x=0;x<26;x++) {
				if (mx[x]==0) continue;
				for (int y=0;y<26;y++) {
					if (mx[y]==0) continue;
					if (x==y) res+=mx[x]*2-1;
					else res+=mx[x]*mx[y];
				}
			}
			cout<<res<<'\n';
		}
	}
}
int main() {
	freopen("PREANDSUF.INP","r",stdin);
	freopen("PREANDSUF.ANS","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) cin>>s[i];
    sub1::solve();
}
