#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,q;
long long a[N+5];
long long sum[N+5];
vector<pair<long long,long long>>p;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>q;
	p.push_back({0,0});
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (a[i]==a[i-1]+1) p[p.size()-1].second++;
		else p.push_back({a[i],a[i]});
	}
	for (int i=1;i<(int)p.size();i++) {
		sum[i]=sum[i-1]+p[i].first-p[i-1].second-1;
	}
	while (q--) {
		long long k;
		cin>>k;
		int lo=1,hi=p.size()-1,ans=0;
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (sum[mid]<k) {
				lo=mid+1;
				ans=mid;
			} else hi=mid-1;
		}
		k-=sum[ans];
		cout<<p[ans].second+k<<'\n';
	}
}