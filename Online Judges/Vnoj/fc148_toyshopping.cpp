#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,x;
int a[N+5],b[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		bool flag=true;
		cin>>n>>x;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			b[i]=a[i];
			if (a[i]>a[i-1]) flag=false;
		}
		if (flag) {
			cout<<"YES"<<'\n';
			continue;
		}
		sort(b+1,b+1+n);
		for (int i=n-x+1;i<=x;i++) {
			if (a[i]!=b[i]) {
				flag=true;
				break;
			}
		}
		if (!flag) cout<<"YES"<<'\n';
		else cout<<"NO"<<'\n';
	}
}