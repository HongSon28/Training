#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=18;
int t,n;
long long s,a[N+5],sum[N+5],mn[LG+5][N+5];
long long get(int l,int r) {
	int k=__lg(r-l+1);
	return min(mn[k][l],mn[k][r-(1<<k)+1]);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while(t--) {
    	cin>>n>>s;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		sum[i]=sum[i-1]+a[i];
    		mn[0][i]=sum[i];
    	}
    	for (int i=1;(1<<i)<=n;i++) {
    		for (int j=1;j+(1<<i)-1<=n;j++) mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
    	}
    	int rl=-1,rr=-1;
    	for (int i=1;i<=n;i++) {
    		int lo=i,hi=n,res=-1;
    		while (lo<=hi) {
    			int mid=(lo+hi)/2;
    			if (get(i,mid)>=sum[i-1]-s) {
    				res=mid;
    				lo=mid+1;
    			} else hi=mid-1;
    		}
    		if (res!=-1) {
    			if (rl==-1) {
    				rl=i;
    				rr=res;
    			} else if (rr-rl+1<res-i+1) {
    				rl=i;
    				rr=res;
    			} 
    		}
    	}
    	if (rl==-1) cout<<-1<<'\n';
    	else cout<<rl<<' '<<rr<<'\n';
    }	
}