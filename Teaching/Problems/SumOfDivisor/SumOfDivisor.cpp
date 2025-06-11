#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long mod=1e9+7;
int n;
int x[N+5],k[N+5];
long long res=1;
long long power(long long x,long long y) {
	if (y==1) return x%mod;
	long long res=power(x,y/2);
	res=(res*res)%mod;
	if (y&1) res=(res*x)%mod;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    for (int i=1;i<=n;i++) {
    	cin>>x[i]>>k[i];
    	long long temp=power(x[i],k[i]+1)-1;
    	if (temp<0) temp+=mod;
    	res*=temp*power(x[i]-1,mod-2)%mod;
    	res%=mod;
    }
    cout<<res;
}