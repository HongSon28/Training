#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,k;
int a[N+5];
int calc(int x) {
	return 1+(n-x)/k;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		cin>>n>>k;
		int cur=n;
		for (int i=1;i<=n;i+=2) {
			a[i]=cur;
			cur-=calc(i);
		}
		cur=1;
		for (int i=k;i>0;i-=2) {
			a[i]=cur;
			cur+=calc(i);
		}
		for (int i=k+1;i<=n;i++) {
			if (i%2==1) a[i]=a[i-k]-1;
			else a[i]=a[i-k]+1;
		}
		for (int i=1;i<=n;i++) cout<<a[i]<<' ';
		cout<<'\n';
	}
}