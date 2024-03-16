#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,q;
long long a[N+5],b[N+5],m[N+5],sum[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>q;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=1;i<=n;i++) {
		long long t;
		cin>>t;
		b[i]=b[i-1]+t;
		m[i]=max(m[i-1],b[i-1]+a[i]);
	}
	while (q--) {
		long long k;
		cin>>k;
		long long ans=0,lo=1,hi=n;
		while (lo<=hi) {
			long long mid=(lo+hi)/2;
			if (m[mid]<=k) {
				ans=mid;
				lo=mid+1;
			} else hi=mid-1;
		}
		cout<<sum[ans]<<'\n';
	}
}