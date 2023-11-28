#include<bits/stdc++.h>
using namespace std;
const int N=50;
int t,n,x;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n>>x;
		int res=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		for (int i=1;i<=n;i++) res=max(res,a[i]-a[i-1]);
		res=max(res,(x-a[n])*2);
		cout<<res<<'\n';
	}
}