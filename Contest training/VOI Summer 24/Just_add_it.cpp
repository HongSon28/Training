#include<bits/stdc++.h>
using namespace std;
long long mod=10000007;
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long res=power(x,y/2);
	res=(res*res)%mod;
	if (y&1) res=(res*x)%mod;
	return res;
}
int n,k;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin>>n>>k) {
    	if (n==0&&k==0) return 0;
    	long long res=power(n,k)+2*power(n-1,k);
    	res+=power(n,n)+2*power(n-1,n-1);
    	cout<<res%mod<<'\n';
    }
}