#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string a,b;
long long power[N+5];
long long base=311,mod=1e9+7;
long long ha[N+5],hb[N+5];
void prep() {
	power[0]=1;
	for (int i=1;i<=N;i++) power[i]=power[i-1]*base%mod;
	a=' '+a,b=' '+b;
	for (int i=1;i<(int)a.size();i++) ha[i]=(ha[i-1]*base+(int)a[i])%mod;
	for (int i=1;i<(int)b.size();i++) hb[i]=(hb[i-1]*base+(int)b[i])%mod;
}
long long geta(int l,int r) {
	return (ha[r]-ha[l-1]*power[r-l+1]+mod*mod)%mod;
}
long long getb(int l,int r) {
	return (hb[r]-hb[l-1]*power[r-l+1]+mod*mod)%mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>a>>b;
    int n=a.size(),m=b.size();
    prep();
    for (int i=1;i+m-1<=n;i++) 
    	if (geta(i,i+m-1)==getb(1,m)) cout<<i<<' ';
}