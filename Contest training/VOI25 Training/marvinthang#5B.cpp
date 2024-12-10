#include<bits/stdc++.h>
using namespace std;
const int N=100,M=1e4;
int n,l,r,k;
int a[N+5];
int dpl[N+5][M+5],dpr[N+5][M+5],f[N+5][M+5],sum,res;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>l>>r>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=l;i<=r;i++) sum+=a[i];
    for (int i=1;i<l;i++) {
    	for (int j=l-1;j<=r;j++) 
    		for (int t=0;t<=k;t++) f[j][t]=dpl[j][t];
    	for (int j=l;j<=r;j++) {
    		int cost=j-i;
    		for (int t=1;t<=k;t++) dpl[j][t]=max({dpl[j][t],f[j][t],dpl[j-1][t]});
    		for (int t=cost;t<=k;t++) {
    			dpl[j][t]=max(dpl[j][t],f[j-1][t-cost]-a[i]+a[j]);
    			//cout<<i<<' '<<j<<' '<<t<<' '<<a[i]<<' '<<a[j]<<' '<<f[j-1][t-cost]-a[i]+a[j]<<' '<<dpl[j][t]<<endl;
    		}
    	}
    }
    for (int i=r+1;i<=n;i++) {
    	for (int j=l;j<=r+1;j++)
    		for (int t=0;t<=k;t++) f[j][t]=dpr[j][t];
    	for (int j=r;j>=l;j--) {
    		int cost=i-j;
    		for (int t=1;t<=k;t++) dpr[j][t]=max({dpr[j][t],f[j][t],dpr[j+1][t]});
    		for (int t=cost;t<=k;t++) {
    			dpr[j][t]=max(dpr[j][t],f[j+1][t-cost]-a[i]+a[j]);
    			//cout<<i<<' '<<j<<' '<<t<<' '<<dpr[j][t]<<endl;
    		}
    	}
    }
    for (int i=0;i<=n+1;i++) {
    	for (int j=1;j<=k;j++) {
    		dpl[i][j]=max(dpl[i][j],dpl[i][j-1]);
    		dpr[i][j]=max(dpr[i][j],dpr[i][j-1]);		
    	} 
    }
    for (int i=l;i<=r+1;i++) {
    	for (int j=0;j<=k;j++) res=max(res,dpl[i-1][j]+dpr[i][k-j]);
    }
    cout<<sum-res;
}