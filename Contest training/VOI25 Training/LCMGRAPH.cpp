#include<bits/stdc++.h>
using namespace std;
const int N=3e5,LG=19;
int n,k;
long long a[N+5];
int p[N+5],st,ed;
bool b[N+5];
long long rmq[N+5][LG+5];
long long dp[N+5],inf=1e18;
int trace[N+5];
long long lcm(long long x,long long y) {
	return x*y/__gcd(x,y);
}
long long cost(int l,int r) {
	r--;
	int k=__lg(r-l+1);
	return lcm(rmq[l][k],rmq[r-(1<<k)+1][k]);
}
vector<int>tr;
int main() { 
	freopen("LCMGRAPH.INP","r",stdin);
	freopen("LCMGRAPH.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<n;i++) rmq[i][0]=lcm(a[i],a[i+1]);
    for (int i=1;(1<<i)<n;i++) {
    	for (int j=1;j+(1<<i)-1<n;j++) rmq[j][i]=lcm(rmq[j][i-1],rmq[j+(1<<(i-1))][i-1]);
    }
    st=n+1;
    for (int i=1;i<=k;i++) {
    	cin>>p[i];
    	b[p[i]]=true;
    	st=min(st,p[i]);
    	ed=max(ed,p[i]);
    }
    dp[st]=0;
    for (int i=st+1;i<=ed;i++) {
    	dp[i]=inf;
    	for (int j=i-1;j>=1;j--) {
    		long long cur=dp[j]+cost(j,i);
    		if (cur<dp[i]) {
    			dp[i]=cur;
    			trace[i]=j;
    		}
    		if (b[j]) break;
    	}
    }
    tr.push_back(ed);
    while (tr.back()!=st) {
    	tr.push_back(trace[tr.back()]);
    }
    cout<<dp[ed]<<'\n';
    cout<<tr.size()-1<<'\n';
    for (int i=0;i<(int)tr.size()-1;i++) cout<<tr[i]<<' '<<tr[i+1]<<'\n';
}