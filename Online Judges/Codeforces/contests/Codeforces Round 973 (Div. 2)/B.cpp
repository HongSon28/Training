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
		for (int i=1;i<n-1;i++) a[n-1]-=a[i];
		cout<<a[n]-a[n-1]<<'\n';
	}
}