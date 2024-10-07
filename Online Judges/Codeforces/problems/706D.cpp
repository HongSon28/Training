#include<bits/stdc++.h>
using namespace std;
struct Node {
	int next[2];
	int cnt,ed;
	Node() {
		next[0]=next[1]=-1;
		cnt=ed=0;
	}
};
vector<Node>trie(1);
void add(int x) {
	int v=0;
	for (int i=31;i>=0;i--) {
		int cur=(x>>i&1);
		if (trie[v].next[cur]==-1) {
			trie[v].next[cur]=trie.size();
			trie.emplace_back();
		}
		v=trie[v].next[cur];
		trie[v].cnt++;
		//cout<<v<<' '<<trie[v].cnt<<endl;
	}
	trie[v].ed++;
	//cout<<endl;
}
void del(int x) {
	int v=0;
	for (int i=31;i>=0;i--) {
		int cur=(x>>i&1);
		v=trie[v].next[cur];
		trie[v].cnt--;
		//cout<<v<<' '<<trie[v].cnt<<endl;
	}
	trie[v].ed--;
	//cout<<endl;
}
int q;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>q;
    add(0);
    while (q--) {
    	char c;
    	int x;
    	cin>>c>>x;
    	if (c=='+') add(x);
    	else if (c=='-') del(x);
    	else {
    		int ans=0;
    		int v=0;
    		for (int i=31;i>=0;i--) {
    			int cur=(x>>i&1);
    			int pri=1-cur;
    			if (trie[v].next[pri]!=-1&&trie[trie[v].next[pri]].cnt!=0) {
    				ans|=(pri<<i);
    				v=trie[v].next[pri];
    				//cout<<pri<<' '<<v<<' '<<trie[v].cnt<<endl;
    			} else {
    				ans|=(cur<<i);
    				v=trie[v].next[cur];
    				//cout<<cur<<' '<<v<<' '<<trie[v].cnt<<endl;
    			}
    		}
    		cout<<(x^ans)<<'\n';
    	}
    }
}