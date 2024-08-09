#include<bits/stdc++.h>
using namespace std;
const int N=500;
int k,x,n;
int a[N+5][N+5],row[N+5][N+5],col[N+5][N+5],dp[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>k;
	while (k--) {
		cin>>n;
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++){
				cin>>x;
				row[i][j]=(row[i][j-1]+x)%2;
				col[j][i]=(col[j][i-1]+x)%2;
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				dp[i][j]=0;
				if (!dp[i-1][j]&&!row[i][j]) dp[i][j]=1;
				if (!dp[i][j-1]&&!col[j][i]) dp[i][j]=1;
			}
		}
		if (dp[n][n]) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n'; 	
	}
}