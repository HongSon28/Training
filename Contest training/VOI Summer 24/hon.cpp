#include<bits/stdc++.h>
using namespace std;
const int N=200;
#define ll long long
int n,k;
ll a[N+5][N+5];
ll mx1[N+5],mx2[N+5];
void solve1() {
	ll res=0;
	ll dp[N+5][N+5][2]={};
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n+i-1;j++) {
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j-1][0])+a[i][j];
			dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][1])+a[i][j];
			dp[i][j][1]=max(dp[i][j][1],dp[i][j][0]+mx1[i]-a[i][j]);
		}
	}
	for (int i=n+1;i<2*n;i++) {
		int len=2*n-1-(i-n);
		int l=i-n+1,r=l+len-1;
		for (int j=l;j<=r;j++) {
			dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j-1][0])+a[i][j];
			dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][1])+a[i][j];
			dp[i][j][1]=max(dp[i][j][1],dp[i][j][0]+mx1[i]-a[i][j]);
			if (i==2*n-1) res=max(res,dp[i][j][1]);
		}
	}
	cout<<res;
}
ll dp[N+5][N+5][N+5][2]={};
void solve2() {
	ll res=0;	
	for (int i=1;i<=n;i++) {
		for (int j1=1;j1<n+i-1;j1++) {
			for (int j2=j1+1;j2<=n+i-1;j2++) {
				for (int d1=0;d1<=1;d1++) {
					for (int d2=0;d2<=1;d2++) {
						if (j1-d1>=j2-d2) continue;
						dp[i][j1][j2][0]=max(dp[i][j1][j2][0],dp[i-1][j1-d1][j2-d2][0]+a[i][j1]+a[i][j2]);
						dp[i][j1][j2][1]=max(dp[i][j1][j2][1],dp[i-1][j1-d1][j2-d2][1]+a[i][j1]+a[i][j2]);
					}
				}
				if (max(a[i][j1],a[i][j2])>=mx2[i])
					dp[i][j1][j2][1]=max(dp[i][j1][j2][1],dp[i][j1][j2][0]+mx1[i]+mx2[i]-a[i][j1]-a[i][j2]);
				else 
					dp[i][j1][j2][1]=max(dp[i][j1][j2][1],dp[i][j1][j2][0]+mx1[i]-min(a[i][j1],a[i][j2]));
				//cout<<i<<' '<<j1<<' '<<j2<<' '<<dp[i][j1][j2][0]<<' '<<dp[i][j1][j2][1]<<endl;
			}
		}
	}
	for (int i=n+1;i<2*n;i++) {
		int len=2*n-1-(i-n);
		int l=i-n+1,r=l+len-1;
		for (int j1=l;j1<r;j1++) {
			for (int j2=j1+1;j2<=r;j2++) {
				for (int d1=0;d1<=1;d1++) {
					for (int d2=0;d2<=1;d2++) {
						if (j1-d1>=j2-d2) continue;
						dp[i][j1][j2][0]=max(dp[i][j1][j2][0],dp[i-1][j1-d1][j2-d2][0]+a[i][j1]+a[i][j2]);
						dp[i][j1][j2][1]=max(dp[i][j1][j2][1],dp[i-1][j1-d1][j2-d2][1]+a[i][j1]+a[i][j2]);
					}
				}
				if (max(a[i][j1],a[i][j2])>=mx2[i])
					dp[i][j1][j2][1]=max(dp[i][j1][j2][1],dp[i][j1][j2][0]+mx1[i]+mx2[i]-a[i][j1]-a[i][j2]);
				else 
					dp[i][j1][j2][1]=max(dp[i][j1][j2][1],dp[i][j1][j2][0]+mx1[i]-min(a[i][j1],a[i][j2]));
				if (i==2*n-1) res=max(res,dp[i][j1][j2][1]);
			}
		}
	}
	cout<<res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n+i-1;j++) {
			cin>>a[i][j];
			if (a[i][j]>mx1[i]) {
				mx2[i]=mx1[i];
				mx1[i]=a[i][j];
			} else mx2[i]=max(mx2[i],a[i][j]);
		}
	}
	for (int i=n+1;i<2*n;i++) {
		int len=2*n-1-(i-n);
		int l=i-n+1,r=l+len-1;
		for (int j=l;j<=r;j++) {
			cin>>a[i][j];
			if (a[i][j]>mx1[i]) {
				mx2[i]=mx1[i];
				mx1[i]=a[i][j];
			} else mx2[i]=max(mx2[i],a[i][j]);
		}
	}
	if (k==1) solve1();
	else solve2();
}