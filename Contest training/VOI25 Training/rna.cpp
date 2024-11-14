#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
string s[N+5],t[N+5];
int id[26];
vector<int>vc[2];
struct Trie{
	struct Node{
		int c[4];
		vector<int>v;
	};
	int n;
	vector<Node>trie;
	void init_node(int id) {
		memset(trie[id].c,-1,sizeof(trie[id].c));
	}
	void init() {
		n=1;
		trie.resize(1);
		init_node(0);
	}
	void add_string(const int &ids,const string &s) {
		int cur=0;
		for (auto i:s) {
			if (trie[cur].c[id[i-'A']]==-1) {
				trie.emplace_back();
				trie[cur].c[id[i-'A']]=n;
				init_node(n);
				n++;
			}
			cur=trie[cur].c[id[i-'A']];
			trie[cur].v.push_back(ids);
		}
	}
	void walk(const int &ids,const string &s) {
		int cur=0;
		for (auto i:s) {
			if (trie[cur].c[id[i-'A']]==-1) return;
			cur=trie[cur].c[id[i-'A']];
		}
		vc[ids]=trie[cur].v;
	}
} trie1,trie2;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    trie1.init(),trie2.init();
    id['A'-'A']=0;
    id['U'-'A']=1;
    id['G'-'A']=2;
    id['C'-'A']=3;
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>s[i];
    	t[i]=s[i];
    	reverse(t[i].begin(),t[i].end());
    	trie1.add_string(i,s[i]);
    	trie2.add_string(i,t[i]);
    }
    while (m--) {
    	cin>>s[0]>>t[0];
    	reverse(t[0].begin(),t[0].end());
    	trie1.walk(0,s[0]);
    	trie2.walk(1,t[0]);
    	int j=0,res=0;
    	for (int i=0;i<(int)vc[0].size();i++) {
    		while (j<(int)vc[1].size()&&vc[1][j]<vc[0][i]) j++;
    		if (j<(int)vc[1].size()&&vc[0][i]==vc[1][j]) res++;
    	}
    	cout<<res<<'\n';
    }
}