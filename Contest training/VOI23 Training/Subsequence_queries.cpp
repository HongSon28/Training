#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q,x,y,last;
string s[N+5];
vector<int>nxt[N+5][26];
map<pair<int,int>,int>asked;
bool check(int x,int y) {
	int pos=0;
	for (int i=1;i<(int)s[x].size();i++) {
		//cout<<pos<<' '<<s[x][i]<<' '<<y<<' '<<nxt[y][s[x][i]-'a'][pos]<<endl;
		pos=nxt[y][s[x][i]-'a'][pos];
		if (pos==-1) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for (int i=1;i<=n;i++) {
		cin>>s[i];
		s[i]=' '+s[i];
		for (char c='a';c<='z';c++){
			last=-1;
			nxt[i][c-'a'].resize(s[i].size()+1);
			for (int j=s[i].size()-1;j>=0;j--) {
				nxt[i][c-'a'][j]=last;
				if (s[i][j]==c) last=j;
			}
		}
	}	
	while (q--) {
		cin>>x>>y;
		if (asked[{x,y}]==1) {
			cout<<"NO"<<'\n';
			continue;
		}
		if (asked[{x,y}]==2) {
			cout<<"YES"<<'\n';
			continue;
		}
		if (s[x].size()>s[y].size()) swap(x,y);
		if (s[x].size()<s[y].size()) {
			if (check(x,y)) {
				asked[{x,y}]=2;
				asked[{y,x}]=2;
				cout<<"YES"<<'\n';		
			} else {
				asked[{x,y}]=1;
				asked[{y,x}]=1;
				cout<<"NO"<<'\n';
			}
		} else {
			if (s[x]==s[y]) {
				asked[{x,y}]=2;
				asked[{y,x}]=2;
				cout<<"YES"<<'\n';		
			} else {
				asked[{x,y}]=1;
				asked[{y,x}]=1;
				cout<<"NO"<<'\n';
			}
		}
	}
}