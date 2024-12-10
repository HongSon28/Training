#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7;
long long power(long long x,long long y) {
	long long res=1;
	while (y>0) {
		if (y&1) res=(res*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return res;
}
int n,a,b;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n;
    while (n--) {
    	cin>>a>>b;
    	cout<<power(a,b)<<'\n';
    }
}