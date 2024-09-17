#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long res=1;
bool check(long long t) {
	long long cnt=0;
	for (long long i=1;i<=n;i++) {
		long long temp=t/i;
		if (temp*i==t) temp--;
		cnt+=min(m,temp);
	}
	return (cnt<k);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>m>>k;
	long long lo=1,hi=n*m;
	while (lo<=hi) {
		long long mid=(lo+hi)/2;
		if (check(mid)) {
			res=mid;
			lo=mid+1;
		} else hi=mid-1;
	}
	cout<<res;
}