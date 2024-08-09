#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
struct Trie{
	struct Node{
		int child[2];
		int cnt,exist;
	} node[N+5];
	int cur;
	Trie():cur(0) {
		node[0].child[0]=node[0].child[1]=-1;
		node[0].cnt=node[0].exist=0;
	}
	int new_node() {
		cur++;
		node[cur].child[0]=node[cur].child[1]=-1;
		node[cur].cnt=node[cur].exist=0;
		return cur;
	}
	void add_string(string s) {
		int pos=0;
		for (auto c:s) {
			int f=c-'0';
			if (node[pos].child[f]==-1) node[pos].child[f]=new_node();
			pos=node[pos].child[f];
			node[pos].cnt++;
		}
		node[pos].exist++;
	}
} trie;
int n,m;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>m>>n;
    while (m--) {
    	int t;
    	char c;
    	string s;
    	cin>>t;
    	while (t--) {
    		cin>>c;
 			s+=c;
    	}
    	trie.add_string(s);
    }
    while (n--) {
    	int t,pos=0,res=0;
    	char c;
    	string s;
    	bool flag=true;
    	cin>>t;
    	while (t--) {
    		cin>>c;
    		s+=c;
    	}
    	for (auto c:s) {
    		int f=c-'0';
    		if (trie.node[pos].child[f]==-1) {
    			flag=false;
    			break;
    		}
    		pos=trie.node[pos].child[f];
    		res+=trie.node[pos].exist;
    	}
    	if (flag) res+=trie.node[pos].cnt-trie.node[pos].exist;
    	cout<<res<<'\n';
    }
}