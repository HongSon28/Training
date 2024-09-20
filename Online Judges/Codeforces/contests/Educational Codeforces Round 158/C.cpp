#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		if (n==1) {
			cout<<0<<'\n';
			continue;
		}
		long long mx=0,mn=1e18;
		for (int i=1;i<=n;i++) {
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
		if (mx==mn) {
			cout<<0<<'\n';
			continue;
		}
		long long res=__lg(mx-mn);
		res++;
		cout<<res<<'\n';
		if (res>n) continue;
		for (int i=1;i<=res;i++) cout<<mn<<' ';
		cout<<'\n';
	}
}