#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,m,k;
long long a[N+5],d[N+5],f[N+5];
bool check(long long t) {
	long long l=-1,r;
	for (int i=2;i<=n;i++) {
		if (a[i]-a[i-1]<=t) continue;
		if (l!=-1) return false;
		l=a[i-1];
		r=a[i];
	}
	long long x=r-t,y=l+t;
	if (l==-1) return true;
	int j=k;
	for (int i=1;i<=m;i++) {
		while (j>=2&&d[i]+f[j]>y) j--;
		if (d[i]+f[j]>=x&&d[i]+f[j]<=y) return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m>>k;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	for (int i=1;i<=m;i++) cin>>d[i];
    	for (int i=1;i<=k;i++) cin>>f[i];
    	sort(d+1,d+1+m);
    	sort(f+1,f+1+k);
    	long long lo=0,hi=2e9,res=2e9;
    	while (lo<=hi) {
    		long long mid=(lo+hi)/2;
    		if (check(mid)) {
    			res=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	cout<<res<<'\n';
    }
}