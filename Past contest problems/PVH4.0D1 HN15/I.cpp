#include<bits/stdc++.h>
using namespace std;
const int N=2e4;
int t,n,k;
int a[N+5];
multiset<int>s;
bool check(int mx) {
	s.clear();
	int cnt=0;
	for (int i=1;i<=n;i++) s.insert(a[i]);
	while (!s.empty()) {
		int cur=mx;
		cnt++;
		while (!s.empty()) {
			auto it=s.upper_bound(cur);
			if (it==s.begin()) break;
			it--;
			cur-=(*it);
			s.erase(it);
		}
	}
	return (cnt<=k);
}
int main() {
	freopen("I.INP","r",stdin);
	freopen("I.OUT","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n>>k;
		int lo=1,hi=0,res=1e9;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			lo=max(lo,a[i]);
			hi+=a[i];
		}
		while (lo<=hi) {
			int mid=(lo+hi)/2;
			if (check(mid)) {
				hi=mid-1;
				res=mid;
			} else lo=mid+1;
		}
		cout<<res<<'\n';
	}
}