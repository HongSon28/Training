#include<bits/stdc++.h>
using namespace std;
const int N=100;
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
		sort(a+1,a+1+n);
		long long res=0;
		for (int i=2;i<=n;i++) res+=a[i]-a[i-1];
		cout<<res<<'\n';
	}
}