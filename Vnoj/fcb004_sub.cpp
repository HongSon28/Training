#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int a[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>t;
	while (t--) {
		int mx=INT_MIN;
		cin>>n;
		for (int i=1;i<=n;i++) {
			cin>>a[i];
			mx=max(mx,a[i]);
		}
		if (mx<=0) {
			cout<<mx<<' '<<mx<<'\n';
			continue;
		}
		int sum1=0,sum2=0,cur=0;
		for (int i=1;i<=n;i++) {
			cur+=a[i];
			if (cur<0) cur=0;
			sum2=max(sum2,cur);
			sum1+=max(0,a[i]);
		}
		cout<<sum1<<' '<<sum2<<'\n';
	}
}