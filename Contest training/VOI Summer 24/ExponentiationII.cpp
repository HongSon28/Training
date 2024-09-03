#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long power(long long x,long long y,long long mod) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	long long res=power(x,y/2,mod);
	res=(res*res)%mod;
	if (y&1) res=(res*x)%mod;
	return res;
}
int n,a,b,c;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    while (n--) {
    	cin>>a>>b>>c;
    	cout<<power(a,power(b,c,mod-1),mod)<<'\n';
    }
}