#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
bool check(int i,int j) {
	int cur=0;
	for (int p=i;p<=j;p++) {
		if (s[p]=='(') cur++;
		else cur--;
		if (cur<0) return false;
	}
	return cur==0;
}
int main() {
	freopen("STBRAC.INP","r",stdin);
	freopen("STBRAC.ANS","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>n>>m>>s;
	s=' '+s;
	while (m--) {
		int type;
		cin>>type;
		if (type==0) {
			int i;
			char c;
			cin>>i>>c;
			s[i]=c;
		} else {
			int i,j;
			cin>>i>>j;
			cout<<check(i,j);
		}
	}
}
