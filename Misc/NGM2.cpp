#include<bits/stdc++.h>
using namespace std;
int n,k;
long long a[16];
long long lcm(long long x,long long y) {
	return x*y/__gcd(x,y);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>n>>k;
	long long res=n;
	for (int i=0;i<k;i++) cin>>a[i];
	for (int mask=1;mask<(1<<k);mask++) {
		long long cur=1;
		for (int i=0;i<k;i++) {
			if (mask>>i&1) {
				cur=lcm(cur,a[i]);
			}
		}
		if (__builtin_popcount(mask)&1) res-=n/cur;
		else res+=n/cur;
		//cout<<mask<<' '<<cur<<' '<<g<<endl;
	}
	cout<<res;
}