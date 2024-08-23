#include<bits/stdc++.h>
using namespace std;
const int N=2000;
int n;
int dp[N+5][N+5],trace[N+5][N+5];
int a[N+5];
bool maxi(int &x,const int &y) {
	if (x<y) {
		x=y;
		return true;
	}
	return false;
}
void tr(int l,int r) {
	if (l==r-1) {
		cout<<l<<' '<<r<<'\n';
		return;
	}
	int i=trace[l][r];
	if (i==-1) return;
	cout<<l<<' '<<i<<'\n';
	tr(l+1,i-1);
	tr(i+1,r);
}
int main() {
	freopen("party.inp","r",stdin);
	freopen("party.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    memset(trace,-1,sizeof(trace));
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int len=1;len<n;len+=2) {
    	for (int l=1;l+len<=n;l++) {
    		int r=l+len;
    		trace[l][r]=l+1;
    		for (int i=l+1;i<=r;i+=2) {
    			if (maxi(dp[l][r],dp[l+1][i-1]+dp[i+1][r]+(a[l]==a[i]))) 
    				trace[l][r]=i;
    		}
    	}
    }
    cout<<dp[1][n]<<'\n';
    tr(1,n);
}