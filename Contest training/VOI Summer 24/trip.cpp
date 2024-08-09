#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k,d;
int t[N+5];
long long h[N+5],dp[N+5],inf=1e18;
int u,v;
vector<vector<long long>>bit;
void update(int x,int y,long long val) {
	for (int i=x+1;i<=u;i+=(i&-i)) {
		for (int j=y+1;j<=v;j+=(j&-j)) bit[i][j]=max(bit[i][j],val);
	}
}
long long get(int x,int y) {
	long long ans=-inf;
	for (int i=x+1;i>0;i-=(i&-i))
		for (int j=y+1;j>0;j-=(j&-j))
			ans=max(ans,bit[i][j]);
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //cout.tie(nullptr);
    cin>>n>>k>>d;
    for (int i=1;i<=n;i++) cin>>h[i];
    for (int i=1;i<n;i++) cin>>t[i];
    u=n/k+1,v=k;
    bit.resize(u+1);
    for (int i=0;i<=u;i++) {
    	bit[i].resize(v+1);
    	for (int j=0;j<=v;j++) bit[i][j]=-inf;
    }
    dp[n]=h[n];
    update(n/k,n%k,dp[n]-n/k*d);
    for (int i=n-1;i>=1;i--) {
    	dp[i]=i/k*d+h[i];
    	int col=i%k;
    	long long mx=-inf;
    	int x=(i+t[i])/k,y=(i+t[i])%k;
    	mx=max(mx,get(x,y));
    	if (x>0) mx=max(mx,get(x-1,k-1));
    	if (col>0) {
    		if (y<col-1) {
    			mx=max(mx,get(x,y)+d);
    			if (x>0) mx=max(mx,get(x-1,col-1)+d);
    		} else mx=max(mx,get(x,col-1)+d);
    	}
    	dp[i]+=mx;
    	update(i/k,i%k,dp[i]-i/k*d);
    }
    cout<<dp[1];
}
