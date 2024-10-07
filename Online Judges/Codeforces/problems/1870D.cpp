#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n;
long long c[N+5],k;
long long a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=1;i<=n;i++) cin>>c[i];
		cin>>k;
		for (int i=n-1;i>=1;i--) c[i]=min(c[i],c[i+1]);
		a[1]=k/c[1];
		k-=c[1]*a[1];
		for (int i=2;i<=n;i++) {
			long long cur=0;
			long long dif=c[i]-c[i-1];
			if (dif==0) cur=a[i-1];
			else {
				cur=min(a[i-1],k/dif);
			}
			a[i]=cur;
			k-=dif*a[i];
		}
		for (int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<'\n';
	}
}