#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long k;
pair<long long,int>a[N+5],b[N+5];
bool comp(pair<long long,int>x,pair<long long,int>y) {
	if (x.first!=y.first) return x.first<y.first;
	return x.second>y.second;
}
vector<int>v;
bool used[N+5];
bool check(long long t) {
	v.clear();
	for (int i=1;i<=n;i++) used[i]=false;
	for (int i=1;i<n;i++) {
		if (v.size()<n/2-1&&!a[i].second&&a[i].first<t) {
			v.push_back(i);
			used[i]=true;
		} else if (!a[i].second&&a[i].first<t) return false;
	}
	for (int i=1;i<n;i++) {
		if (v.size()<n/2-1&&a[i].second&&a[i].first<t) {
			v.push_back(i);
			used[i]=true;
		}
	}
	long long sum=0;
	for (int i=1;i<n;i++) 
		if (a[i].second&&a[i].first<t&&!used[i]) 
			sum+=t-a[i].first;
	return (sum<=k);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>k;
		for (int i=1;i<=n;i++) cin>>a[i].first;
		for (int i=1;i<=n;i++) cin>>a[i].second;
		sort(a+1,a+1+n,comp);
		for (int i=1;i<=n;i++) b[i]=a[i];
		long long res1=b[n].first+b[n/2].first;
		for (int i=n;i>=1;i--) {
			if (b[i].second) {
				b[i].first+=k;
				sort(b+1,b+1+n);
				res1=b[n].first+b[n/2].first;
				break;
			}
		}
		long long lo=a[n/2].first,hi=2e9,res2=0;
		while (lo<=hi) {
			long long mid=(lo+hi)/2;
			if (check(mid)) {
				lo=mid+1;
				res2=mid;
			} else hi=mid-1;
		}
		cout<<max(res1,res2+a[n].first)<<'\n';
	}
}