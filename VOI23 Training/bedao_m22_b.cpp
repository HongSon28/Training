#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int a[N+5];
long long c[23];
long long res;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		c[a[i]%23]++;
	}
	for (int i=0;i<23;i++) res+=c[i]*(c[i]-1)/2;
	for (int i=1;i<=n;i++) {
		for (int j=i+1;j<=n;j++) {
			if (j-i>5) break;
			res-=(abs(a[i]-a[j])%23==0);
		}
	}
	cout<<res;
}