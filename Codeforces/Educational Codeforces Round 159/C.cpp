#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5];
set<int>st;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		int mx=INT_MIN;
		st.clear();
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			mx=max(mx,a[i]);
			st.insert(a[i]);
		}
		if (n==1) {
			cout<<1<<'\n';
			continue;
		}
		int g=__gcd(mx-a[1],mx-a[2]);
		for (int i=3;i<=n;i++) g=__gcd(g,mx-a[i]);
		a[n+1]=mx;
		int t=n;
		long long res=0;
		for (int i=1;i<=n;i++) res+=(mx-a[i])/g;
		for (int i=1;i<=n;i++) {
			a[n+1]-=g;
			if (!st.count(a[n+1])) {
				t=i;
				break;
			}
		}
		cout<<res+t<<'\n';
	}
}