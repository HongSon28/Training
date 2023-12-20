#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long m,res,a[N+5],sum[N+5];
set<int>s;
bool check(long long k) {
	int t=lower_bound(a,a+1+n,k)-a-1;
	long long s=k*(k+1)/2;
	s-=sum[t];
	return s<=m;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	s.insert(a[i]);
    }
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long lo=1,hi=1e9;
	while (lo<=hi) {
		long long mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	int t=lower_bound(a,a+1+n,res)-a-1;
	cout<<res-t<<'\n';
	for (int i=1;i<=res;i++) {
		if (!s.count(i)) cout<<i<<' ';
	}
}