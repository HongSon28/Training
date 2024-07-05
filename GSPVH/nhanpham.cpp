#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
const long long MX=3e9+5;
int n;
long long k,a[N+5],sum[N+5],res=MX;
long long s(long long x) {
	return x*(x+1)/2;
}
bool check(long long i,long long t) {
	long long cur=s(t*n+i);
	cur-=sum[n]*t+sum[i];
	return cur>=k;
}
int main() {
	freopen("nhanpham.inp","r",stdin);
	freopen("nhanpham.out","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	sum[i]=sum[i-1]+a[i];
    }	
    for (long long i=1;i<=n;i++) {
    	if (check(i,0)) {
    		res=min(res,i);
    		continue;
    	}
    	long long l=1,r=MX/n+1,ans;
    	while (l<=r) {
    		long long mid=(l+r)/2;
    		if (check(i,mid)) {
    			ans=mid;
    			r=mid-1;
    		} else l=mid+1;
    	}
    	res=min(res,ans*n+i);
    }
    cout<<res;
}