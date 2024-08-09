#include<bits/stdc++.h>
using namespace std;
const int N=500;
int n,s1,s2;
struct dat{
	int x,t,y,r;
	bool operator < (const dat &other) const {
		if (x!=other.x) return x<other.x;
		if (y!=other.y) return y<other.y;
		if (t!=other.t) return t<other.t;
		return r<other.r;
	}
} a[N+5];
long long dp[2][N+5][N+5],inf=1e18;
void mini(long long &x,long long y) {
	x=min(x,y);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>s1>>s2;
    for (int i=1;i<=n;i++) cin>>a[i].x>>a[i].t>>a[i].y>>a[i].r;
    sort(a+1,a+1+n);
    for (int i=0;i<=1;i++)
    	for (int j=0;j<=s1;j++)
    		for (int k=0;k<=s2;k++)
    			dp[i][j][k]=inf;
    dp[0][0][0]=0;
    for (int i=0;i<n;i++) {
    	for (int j=0;j<=s1;j++) {
    		for (int k=0;k<=s2;k++) {
    			mini(dp[1][j][k],dp[0][j][k]);
    			int cur=j+a[i+1].x;
    			if (cur<=s1) mini(dp[1][cur][k],dp[0][j][k]+a[i+1].t);
    			else if (j<s1) mini(dp[1][s1][min(cur-s1+k,s2)],dp[0][j][k]+a[i+1].t);
    			mini(dp[1][j][min(k+a[i+1].y,s2)],dp[0][j][k]+a[i+1].r);
    		}
    	}
    	for (int j=0;j<=s1;j++) {
    		for (int k=0;k<=s2;k++) {
    			dp[0][j][k]=dp[1][j][k];
    			dp[1][j][k]=inf;
    		} 
    	}
    }	
    if (dp[0][s1][s2]==inf) cout<<-1;
    else cout<<dp[0][s1][s2];
}