#include<bits/stdc++.h>
using namespace std;
const int N=4000;
int n;
string s;
int mod=998244353;
int f[N+5][N+5],g[N+5][N+5];
void add(int &x, int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
void sub(int &x, int y) {
	x-=y;
	if (x<0) x+=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>s;
	n=s.size();
	s=' '+s;
	for (int i=1;i<=n;i++) {
		f[i][i]=1;
		if (i<n) {
			if (s[i]==s[i+1]) f[i][i+1]=3;
			else f[i][i+1]=2;
		}
	}
	for (int len=3;len<=n;len++) {
		for (int i=1;i+len-1<=n;i++) {
			int j=i+len-1;
			f[i][j]=f[i][j-1];
			add(f[i][j],f[i+1][j]);
			sub(f[i][j],f[i+1][j-1]);
			if (s[i]==s[j]) {
				add(f[i][j],f[i+1][j-1]);
				add(f[i][j],1);
			} 
		}
	}
	g[1][n]=(s[1]==s[n]);
	for (int i=n-1;i>=1;i--) {
		g[1][i]=g[1][i+1];
		if (s[1]==s[i]) add(g[1][i],1);
	}
	for (int i=2;i<=n;i++) {
		g[i][n]=g[i-1][n];
		if (s[i]==s[n]) add(g[i][n],1);
	}
	for (int l=2;l<n;l++) {
		for (int r=n-1;r>l;r--) {
			g[l][r]=g[l-1][r];
			add(g[l][r],g[l][r+1]);
			sub(g[l][r],g[l-1][r+1]);
			if (s[l]==s[r]) {
				add(g[l][r],g[l-1][r+1]);
				add(g[l][r],1);
			}
		}
	}
	for (int i=1;i<=n;i++) {
		int res=1;
		if (i>1&&i<n) add(res,g[i-1][i+1]);
		for (int j=1;j<=n;j++) {
			if (i==j||s[i]!=s[j]) continue;
			int l=i,r=j;
			if (l>r) swap(l,r);
			res+=(1ll*(f[l+1][r-1]+1)*(g[l-1][r+1]+1))%mod;
			res%=mod;
		}
		cout<<res<<' ';
	}
}