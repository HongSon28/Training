#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,m;
long long A,B,C;
struct train{
	long long u,v,l,r;
	bool operator < (const train &other) const {
		if (l!=other.l) return l<other.l;
		return r<other.r;
	}
} x[N+5];
long long dp[N+5],inf=1e18,res=inf;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>A>>B>>C;
    for (int i=1;i<=m;i++) cin>>x[i].u>>x[i].v>>x[i].l>>x[i].r;
    sort(x+1,x+1+m);
    for (int i=1;i<=m;i++) dp[i]=inf;
    x[0].v=1;
    for (int i=1;i<=m;i++) {
    	long long cur=A*x[i].l*x[i].l+B*x[i].l+C;
    	for (int j=0;j<i;j++) {
    		if (x[i].u!=x[j].v||x[i].l<x[j].r) continue;
    		dp[i]=min(dp[i],-2*A*x[j].r*x[i].l+A*x[j].r*x[j].r-B*x[j].r+dp[j]+cur);
    		cout<<i<<' '<<x[i].l<<' '<<x[j].r<<' '<<-2*A*x[j].r<<' '<<A*x[j].r*x[j].r-B*x[j].r+dp[j]<<endl;
    	} 
    	cout<<x[i].u<<' '<<x[i].v<<' '<<x[i].l<<' '<<x[i].r<<' '<<dp[i]<<endl;
    	if (x[i].v==n) res=min(res,dp[i]+x[i].r*A); 
    }
    cout<<res;
}
