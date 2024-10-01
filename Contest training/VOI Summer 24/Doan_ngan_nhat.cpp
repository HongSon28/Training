#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n;
long long v,a[N+5];
long long mn[N+5];
int res=N+1;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>v;
	for (int i=1;i<=n;i++) cin>>a[i];
	long long sum=0;
	for (int i=1;i<=n;i++) {
		sum+=a[i];
		mn[i]=min(mn[i-1],sum);
		int ans=-1,lo=0,hi=i-1;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (sum-mn[mid]>=v) {
				ans=mid;
				hi=mid-1;
			} else lo=mid+1;
		}
		if (ans!=-1) res=min(res,i-ans);
	}
	if (res==N+1) cout<<-1;
	else cout<<res;
}