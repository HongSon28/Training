#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		long long res=0;
		for (int i=1;i<=n;i++) res+=max(a[i]-a[i-1],0);
		res--;
		cout<<res<<'\n';
	}
}