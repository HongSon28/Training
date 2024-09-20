#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,q;
int a[N+5],c[N+5],res[N+5];
bool check(int x,int k) {
	int sum=0;
	for (int i=0;i<=n;i+=x) {
		if (i>0) sum+=c[min(i+k,n)]-c[i-1];
		else sum+=c[min(i+k,n)];
	}
	int m;
	if (n%2) m=(n+1)/2;
	else m=n/2+1;
	return (sum>=m);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>q;
		for (int i=1;i<=n;i++) c[i]=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			c[a[i]]++;
		}
		for (int i=2;i<=n;i++) c[i]+=c[i-1];
		for (int i=1;i<=n;i++) {
			int lo=0,hi=i-1,ans=i-1;
			while (lo<=hi) {
				int mid=(lo+hi)/2;
				if (check(i,mid)) {
					ans=mid;
					hi=mid-1;
				} else lo=mid+1;
			}
			res[i]=ans;
		}
		while (q--) {
			int x;
			cin>>x;
			cout<<res[x]<<' ';
		}
		cout<<'\n';
	}
}