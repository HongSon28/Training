#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long mod=1e9+7;
int n;
int x[N+5],k[N+5];
long long res=1;
long long val=1,sq=1;
bool sqr=true;
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
    }
    for (int i=1;i<=n;i++) {
    	val*=power(x[i],k[i]);
    	val%=mod;
    	if (k[i]&1) sqr=false;
    	if (sqr) sq=sq*power(x[i],k[i]/2)%mod;
    }
    if (!sqr) {
    	bool div=false;
    	res=val;
    	for (int i=1;i<=n;i++) {
    		if (!div&&k[i]&1) {
    			div=true;
    			res=power(res,(k[i]+1)/2);
    		} else res=power(res,k[i]+1);
    	}
    } else {
    	res=sq;
    	for (int i=1;i<=n;i++) res=power(res,k[i]+1);
    }
    cout<<res;
}