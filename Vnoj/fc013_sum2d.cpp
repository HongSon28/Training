#include<bits/stdc++.h>
using namespace std;
const int N=200;
int n,m,t,x,y,u,v;
long long a[N+5][N+5],sum[N+5][N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>t;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
	while (t--) {
		cin>>x>>y>>u>>v;
		cout<<sum[u][v]-sum[x-1][v]-sum[u][y-1]+sum[x-1][y-1]<<'\n';
	}
}