#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7,n,res;
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	if (y==0) return 1;
	long long k=power(x,y/2);
	k=(k*k)%mod;
	if (y%2==1) k=(k*x)%mod;
	return k;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	res=(power(10,n)+power(8,n))%mod;
	res-=2*power(9,n);
	res=(res%mod+mod)%mod;
	cout<<res;
}