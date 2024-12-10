#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,m;
string a,b;
int f[N+5][N+5],g[N+5][N+5],mod=1024523;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>a>>b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	a=' '+a,b=' '+b;
	f[0][0]=1;
	for (int s=0;s<n+m;s++) {
		for (int a1=0;a1<=n;a1++) {
			int a2=s-a1;
			for (int b1=0;b1<=n;b1++) {
				//cout<<s<<' '<<a1<<' '<<b1<<' '<<dp[s][a1][b1]<<endl;
				if (!f[a1][b1]) continue;
				int b2=s-b1;
				if (a1<n&&b1<n&&a[a1+1]==a[b1+1]) add(g[a1+1][b1+1],f[a1][b1]);
				if (a1<n&&b2<m&&a[a1+1]==b[b2+1]) add(g[a1+1][b1],f[a1][b1]); 
				if (a2<m&&b1<n&&b[a2+1]==a[b1+1]) add(g[a1][b1+1],f[a1][b1]);
				if (a2<m&&b2<m&&b[a2+1]==b[b2+1]) add(g[a1][b1],f[a1][b1]);
			}
		}
		for (int a1=0;a1<=n;a1++) {
			for (int b1=0;b1<=n;b1++) {
				f[a1][b1]=g[a1][b1];
				g[a1][b1]=0;
			}
		}
	}
	cout<<f[n][n];
}