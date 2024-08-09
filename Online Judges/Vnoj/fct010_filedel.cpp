#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
string s[N+5];
set<int>st[26];
vector<int>v;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>s[i];
    	for (auto t:s[i]) st[t-'a'].insert(i);
    }	
    int cur=n;
    while (q--) {
    	char c;
    	cin>>c;
    	if (st[c-'a'].empty()) {
    		cout<<cur<<'\n';
    		continue;
    	}
    	cur-=st[c-'a'].size();
    	v.clear();
    	for (auto i:st[c-'a']) v.push_back(i);
    	for (auto id:v) {
    		for (auto t:s[id]) {
    			if (st[t-'a'].count(id)!=0) st[t-'a'].erase(st[t-'a'].find(id));
    		}
    	}
    	cout<<cur<<'\n';
    }
}