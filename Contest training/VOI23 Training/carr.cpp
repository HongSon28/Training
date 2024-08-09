#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=__lg(N);
int n,m;
int a[N+5],stk[N+5];
int l[N+5],r[N+5],top,root;
vector<vector<long long>>dp;
long long mod=1e9+7;
void dfs(int u) {
	if (l[u]==0&&r[u]==0){
		for (int i=1;i<=m;i++) dp[u][i]=i;
		return;
	}
	if (l[u]!=0) dfs(l[u]);
	if (r[u]!=0) dfs(r[u]);
	dp[u][0]=0;
	for (int i=1;i<=m;i++) {
		if (l[u]!=0&&i==1) {
			dp[u][i]=0;
			continue;
		}
		dp[u][i]=1;
		if (l[u]!=0&&i>1) {
			dp[u][i]=dp[u][i]*dp[l[u]][i-1]%mod;
			//cout<<i<<' '<<u<<' '<<l[u]<<' '<<dp[l[u]][i-1]<<endl;
		}
		if (r[u]!=0) {
			dp[u][i]=dp[u][i]*dp[r[u]][i]%mod;
			//cout<<i<<' '<<u<<' '<<r[u]<<' '<<dp[r[u]][i]<<endl;
		}	
		dp[u][i]=(dp[u][i]+dp[u][i-1])%mod;
		//cout<<u<<' '<<i<<' '<<dp[u][i]<<endl;	
	}
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		if (root==0||a[root]<a[i]) root=i;
		int k=top;		
		while (k>0&&a[stk[k]]<a[i]) k--;
		if (k) r[stk[k]]=i;
		if (k<top) l[i]=stk[k+1];
		stk[++k]=i;
		top=k;
	}
	//for (int i=1;i<=n;i++) cout<<l[i]<<' '<<r[i]<<endl;
	dp.resize(n+1);
	for (int i=1;i<=n;i++) dp[i].resize(m+1);
	dfs(root);
	cout<<dp[root][m]<<endl;
}