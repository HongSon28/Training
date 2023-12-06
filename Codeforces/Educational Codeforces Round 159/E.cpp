#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
string s[N+5];
long long res;
struct Trie{
	struct Node{
		int child[26];
		int cnt;
	} node[N*5+5];
	int cur;
	Trie():cur(0) {
		memset(node[0].child,-1,sizeof(node[0].child));
		node[0].cnt=0;
	}
	int new_node() {
		cur++;
		memset(node[cur].child,-1,sizeof(node[cur].child));
		node[cur].cnt=0;
		return cur;
	}
	void add_string(string s) {
		int pos=0;
		for (auto f:s) {
			int c=f-'a';
			if (node[pos].child[c]==-1) node[pos].child[c]=new_node();
			pos=node[pos].child[c];
			node[pos].cnt++;
		}
	}
} trie;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>s[i];
    	string temp=s[i];
    	reverse(temp.begin(),temp.end());
    	trie.add_string(temp);
    	res+=(long long)s[i].size()*(long long)n*2;
    }
    for (int i=1;i<=n;i++) {
    	int pos=0;
    	for (auto f:s[i]) {
    		int c=f-'a';
    		pos=trie.node[pos].child[c];
    		res-=trie.node[pos].cnt*2;
    	}
    }
    cout<<res;
}