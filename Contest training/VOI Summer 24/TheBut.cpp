#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long power(long long x,long long y) {
	long long res=1;
	while (y>0) {
		if (y&1) res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
long long n,m,k;
bool check() {
	if (k==1) return true;
	if ((n%2)==(m%2)) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m>>k;
    if (!check()) cout<<0;
    else cout<<power(power(2ll,n-1),m-1);
}