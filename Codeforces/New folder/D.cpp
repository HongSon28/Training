#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
int a[N+5],b[N+5];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>t;
	while (t--) {
		cin>>n;
		long long c1=0,c2=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			c1+=(a[i]==1);
			c2+=(a[i]==2);
		}
		sort(a+1,a+1+n);
		long long cur=1,res=0;
		for (int i=2;i<=n;i++) {
			if (a[i]!=a[i-1]) {
				res+=cur*(cur-1)/2;
				cur=1;
			} else cur++;
		}
		res+=cur*(cur-1)/2;
		res+=c1*c2;
		cout<<res<<'\n';
	}
}