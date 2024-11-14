#include<bits/stdc++.h>
using namespace std;
long long n,k,m,mod,res,inv;
int cnt[1<<25];
void dfs1(long long u,int d) {
	if (!d) {
		cnt[u]++;
		return;
	}
	for (int i=1;i<=26;i++) {
		dfs1(((u*33)^i)%mod,d-1);
	}
	return;
}
void dfs2(long long u,int d) {
	if (!d) {
		res+=cnt[u];
		return;
	}
	for (int i=1;i<=26;i++) {
		dfs2(((u^i)*inv)%mod,d-1);
	}
	return;
}
int main() {
	freopen("DECRYPTE.inp","r",stdin);
	freopen("DECRYPTE.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k>>m;
	mod=1,res=0;
	while (m--) mod<<=1;
	for (long long i=1;i<=mod;i++) {
		if ((i*33)%mod==1) inv=i;
	}
	dfs1(0,n/2);
	dfs2(k,n-n/2);
	cout<<res;
	return 0;
}