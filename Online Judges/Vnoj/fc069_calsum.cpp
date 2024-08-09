#include<bits/stdc++.h>
using namespace std;
long long a,n,mod=1e9+7;
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
    cin>>a>>n;
    if (a==1) {
    	cout<<n+1;
    	return 0;
    }
    long long x=power(a,n+1)-1;
    if (x<0) x+=mod;
    cout<<x*power(a-1,mod-2)%mod;
}