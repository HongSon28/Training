#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
string a,b;
long long base=311,mod=1e9+7,power[N+5],hs[N+5];
void prep() {
	power[0]=1;
	for (int i=1;i<=n;i++) {
		power[i]=power[i-1]*base%mod;
		hs[i]=(hs[i-1]*base+(int)a[i])%mod;
	}
}
long long get(long long l,long long r) {
	return (hs[r]-hs[l-1]*power[r-l+1]+mod*mod)%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
	cin>>a>>b;
	n=a.size(),m=b.size();
	a=' '+a;
	prep();
	long long has=0;
	for (auto c:b) has=(has*base+(int)c)%mod;
	for (int i=1;i+m-1<=n;i++) 
		if (get(i,i+m-1)==has) cout<<i<<' ';
}