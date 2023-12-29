#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7,n,m;
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y%2==1) ans=(ans*x)%mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;	
    long long x=1,y=1;
    for (long long i=1;i<=n-m+1;i++) x=(x*i)%mod;
    for (long long i=1;i<=n-2*m+1;i++) y=(y*i)%mod;
    for (long long i=1;i<=m;i++) y=(y*i)%mod;
    cout<<x*power(y,mod-2)%mod;
}