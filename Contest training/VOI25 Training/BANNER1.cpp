#include<bits/stdc++.h>
using namespace std;
int n,q;
string s;
long long mod=1e9+7;
long long c[6];
long long solve(int l,int r) {
	memset(c,0,sizeof(c));
	for (int i=l;i<=r;i++) {
		if (s[i]=='H') c[1]++;
		else if (s[i]=='S') c[2]=(c[1]+c[2])%mod;
		else if (s[i]=='G') c[3]=(c[2]+c[3])%mod;
		else if (s[i]=='2') c[4]=(c[3]+c[4])%mod;
		else c[5]=(c[4]+c[5])%mod;
	}
	return c[5];
}
int main() {
	freopen("BANNER.INP","r",stdin);
	freopen("BANNER.ANS","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>q>>s;
    s=' '+s;
    while (q--) {
    	int l,r;
    	cin>>l>>r;
    	cout<<solve(l,r)<<'\n';
    }
}
