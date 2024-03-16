#include<bits/stdc++.h>
using namespace std;
unsigned long long a,b,mod=1e9+7;
unsigned long long power(unsigned long long x,unsigned long long y) {
	if (y==0) return 1;
	if (y==1) return x%mod;
	unsigned long long ans=power(x,y/2);
	ans=ans*ans%mod;
	if (y%2==1) ans=ans*x%mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>a>>b;
	a%=mod;
	cout<<power(a,b);
}