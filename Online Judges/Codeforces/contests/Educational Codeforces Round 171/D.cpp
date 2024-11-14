#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n,q;
long long a[N+5];
long long sum1[N+5],sum2[N+5],f[N+5],g[N+5];
long long calcsum(int i,int j1,int j2) {
	return sum2[j2]-sum2[j1-1]-sum1[i-1]*(j2-j1+1);
}
pair<int,int>calc(long long x) {
	int ans=0,lo=1,hi=n;
	while (lo<=hi) {
		int mid=(lo+hi)/2;
		if (f[mid]<x) {
			ans=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	x-=f[ans];
	pair<int,int>res;
	res.first=ans+1;
	res.second=res.first+x-1;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
    	sum1[i]=sum1[i-1]+a[i];
    	sum2[i]=sum2[i-1]+sum1[i];
    	f[i]=f[i-1]+n-i+1;
    }
    for (int i=1;i<=n;i++) {
    	g[i]=g[i-1]+sum2[n]-sum2[i-1]-sum1[i-1]*(n-i+1);
    }
    cin>>q;
    while (q--) {
    	long long l,r;
    	cin>>l>>r;
    	pair<int,int>pl=calc(l),pr=calc(r);
    	//cout<<pl.first<<' '<<pl.second<<' '<<pr.first<<' '<<pr.second<<endl;
    	if (pl.first==pr.first) cout<<calcsum(pl.first,pl.second,pr.second)<<'\n';
    	else if (pl.first+1==pr.first) cout<<calcsum(pl.first,pl.second,n)+calcsum(pr.first,pr.first,pr.second)<<'\n';
    	else {
    		long long res=calcsum(pl.first,pl.second,n)+calcsum(pr.first,pr.first,pr.second);
    		res+=g[pr.first-1]-g[pl.first];
    		cout<<res<<'\n';
    	}
    }
}