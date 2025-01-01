#include<bits/stdc++.h>
using namespace std;
const int N=1e6,M=20;
int n;
int a[N+5];
int f[(1<<M)+5],pw[N+5];
int res,mod=1e9+7;
void add(int &x,int y) {
	x+=y;
	if (x>=mod) x-=mod;
}
void del(int &x,int y) {
	x-=y;
	if (x<0) x+=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    pw[0]=1;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
    	f[a[i]]++;
    	pw[i]=pw[i-1]*2;
    	if (pw[i]>=mod) pw[i]-=mod;
    }
    for (int i=0;i<M;i++) {
    	for (int mask=0;mask<(1<<M);mask++) {
    		if (!(mask>>i&1)) f[mask]+=f[mask+(1<<i)];
    	}
    }
    for (int mask=0;mask<(1<<M);mask++) {
    	int cnt=__builtin_popcount(mask);
    	if (cnt&1) del(res,pw[f[mask]]);
    	else add(res,pw[f[mask]]);
    	//cout<<mask<<' '<<cnt<<' '<<f[mask]<<' '<<pw[f[mask]]<<endl;
    }
    cout<<res;
}