#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,m,mod=1337377;
int dp[N+5];
string s,t;
struct Trie{
	struct Node{
		int child[26];
		int cnt;
	} node[N+5];
	int cur;
	Trie():cur(0) {
		memset(node[0].child,-1,sizeof(node[0].child));
		node[0].cnt=0;
	}
	int add_node() {
		cur++;
		memset(node[cur].child,-1,sizeof(node[cur].child));
		node[cur].cnt=0;
		return cur;
	}
	void add(string s) {
		int pos=0;
		for (auto c:s) {
			int f=c-'a';
			if (node[pos].child[f]==-1) node[pos].child[f]=add_node();
			pos=node[pos].child[f];
		}
		node[pos].cnt++;
	}
}trie;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    m=s.size();
    s=' '+s;	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>t;
    	reverse(t.begin(),t.end());
    	trie.add(t);
	}
	dp[0]=1;
	for (int i=1;i<=m;i++) {
		int pos=0;
		for (int j=i;j>=1;j--) {
			int f=s[j]-'a';
			if (trie.node[pos].child[f]==-1) break;
			pos=trie.node[pos].child[f];
			if (trie.node[pos].cnt!=0) {
				dp[i]+=dp[j-1];
				dp[i]%=mod;
			}
		}
	}
	cout<<dp[m];
}