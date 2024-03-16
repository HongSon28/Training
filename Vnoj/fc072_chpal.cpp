#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n,q;
string s;
bool p[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q>>s;
	s=' '+s;
	for (int i=1;i<=n;i++) {
		p[i][i]=true;
		p[i][i+1]=(s[i]==s[i+1]);
	}
	for (int len=3;len<=n;len++) {
		for (int i=1;i+len-1<=n;i++) {
			int j=i+len-1;
			p[i][j]=(p[i+1][j-1]&&(s[i]==s[j]));
		}
	}
	while (q--) {
		int l,r;
		cin>>l>>r;
		cout<<(p[l][r] ? "YES" : "NO")<<'\n';
	}
}