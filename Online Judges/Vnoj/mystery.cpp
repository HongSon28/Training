#include<bits/stdc++.h>
using namespace std;
long long a,mod=20122007,res=1;
long long power(long long a,long long x) {
	if (x==1) return a%mod;
	long long ans=power(a,x/2);
	ans=(ans*ans)%mod;
	if (x%2==1) ans=(ans*a)%mod;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a;
    for (int i=1;i*i<=a;i++) {
    	if (a%i!=0) continue;
    	res*=(power(3,i)-1+mod)%mod;
    	res%=mod;
    	if (a/i!=i) {
    		res*=(power(3,a/i)-1+mod)%mod;
    		res%=mod;
    	}
    }	
    cout<<res;
}