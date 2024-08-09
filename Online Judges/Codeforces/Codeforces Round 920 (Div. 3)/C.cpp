#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long f,a,b;
long long m[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		long long sum=0;
		cin>>n>>f>>a>>b;
		for (int i=1;i<=n;i++) cin>>m[i];
		for (int i=1;i<=n;i++) sum+=min(b,a*(m[i]-m[i-1]));
		if (sum<f) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}