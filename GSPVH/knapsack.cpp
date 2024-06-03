#include<bits/stdc++.h>
using namespace std;
const int N=2207, M=5603;
int n,m;
long long dp[M+5],c[N+5],d[N+5],res;
int main() {
	freopen("knapsack.inp","r",stdin);
	freopen("knapsack.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>c[i];
    for (int i=1;i<=n;i++) cin>>d[i];
    for (int i=1;i<=n;i++) {
    	for (int j=m;j>=c[i];j--) dp[j]=max(dp[j],dp[j-c[i]]+d[i]);
    }
    for (int i=0;i<=m;i++) res=max(res,dp[i]);
    cout<<res;
}