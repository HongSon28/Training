#include<bits/stdc++.h>
using namespace std;
const int N=1e5,M=2e3;
long long n,k,d,t;
long long a[M+5],v[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>k>>d;
		long long c0=0;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			c0+=(a[i]==i);
		}
		for (int i=1;i<=k;i++) {
			cin>>v[i];
		}
		long long res=c0+(d-1)/2;
		for (int i=1;i<d;i++) {
			if (n+(d-i-1)/2<res) break;
			int j=i%k;
			if (j==0) j=k;
			for (int t=1;t<=v[j];t++) {
				a[t]++;
			}
			long long cur=0;
			for (int t=1;t<=n;t++) cur+=(a[t]==t);
			res=max(res,cur+(d-i-1)/2);
		}
		cout<<res<<'\n';
	}
}