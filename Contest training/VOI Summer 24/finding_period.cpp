#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n;
string s;
long long base=311,mod=1e9+7;
long long power[N+5],hs[N+5];
void prep() {
	power[0]=1;
	for (int i=1;i<=n;i++) {
		power[i]=power[i-1]*base%mod;
		hs[i]=(hs[i-1]*base+(int)s[i])%mod;
	}
}
long long get(long long l,long long r) {
	return (hs[r]-hs[l-1]*power[r-l+1]+mod*mod)%mod;
}
bool check(int len) {
	for (int l=1;l<=n;l+=len) {
		int r=l+len-1;
		if (r<=n) {
			if (get(1,len)!=get(l,r)) return false;
		} else { 
			//cout<<1<<' '<<n-l+1<<' '<<l<<' '<<n<<' '<<get(1,n-l+1)<<' '<<get(l,n)<<endl;
			if (get(1,n-l+1)!=get(l,n)) return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>s;
    n=s.size();
    s=' '+s;
    prep();
    for (int i=1;i<=n;i++) {
    	if (check(i)) cout<<i<<' ';
    }
}