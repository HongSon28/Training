#include<bits/stdc++.h>
using namespace std;
const int N=150000;
int t,n;
long long a[N+5],sum[N+5];
long long calc(int k) {
	if (k==n) return 0;
	long long mx=LLONG_MIN,mn=LLONG_MAX;
	int l=1,r=k;
	for (int i=1;i<=n/k;i++) {
		mx=max(mx,sum[r]-sum[l-1]);
		mn=min(mn,sum[r]-sum[l-1]);
		l+=k;
		r+=k;
	}
	//cout<<k<<' '<<mx<<' '<<mn<<endl;
	return mx-mn;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		long long res=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			sum[i]=sum[i-1]+a[i];
		}
		for (int k=1;k*k<=n;k++) {
			if (n%k!=0) continue;
			res=max(res,calc(k));
			res=max(res,calc(n/k));
		} 
		cout<<res<<'\n';
	}
}