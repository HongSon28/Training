#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long power(long long x,long long y) {
	if (y==0) return 1;
	if (y==1) return (x%mod);
	long long ans=power(x,y/2);
	ans=(ans*ans)%mod;
	if (y&1) ans=(ans*x)%mod;
	return ans;
}
long long t,n,m;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>m;
    	cout<<(power((power(2,m)-1+mod)%mod,n)+power((power(2,n)-1+mod)%mod,m)
    		   -power(power(2,n),m)+mod)%mod<<'\n';
    }
}