#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long a[N+5],b[N+5];
long long dif;
long long calc(long long d) {
	for (int i=1;i<=n;i++) b[i]=a[i]-(i-1)*d;
	sort(b+1,b+1+n);
	long long ans=0,md=b[(n+1)/2];
	for (int i=1;i<=n;i++) ans+=abs(b[i]-md);
	return ans;
}
bool check(int pos) {
	long long val1=calc(pos);
	long long val2=calc(pos+1);
	return (val1<val2);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long lo=0,hi=1e9;
	while (lo<=hi) {
		long long mid=(lo+hi)/2;
		if (check(mid)) {
			dif=mid;
			hi=mid-1;
		} else lo=mid+1;
	}
	cout<<calc(dif);
}