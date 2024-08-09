#include<bits/stdc++.h>
using namespace std;
long long mod=1e9+7,n;
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
	cin>>n;
	cout<<power(3,n-1);
}