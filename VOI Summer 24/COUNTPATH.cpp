#include<bits/stdc++.h>
using namespace std;
const int N=2e7;
int n,m;
int mod=1e9+7;
int gt[N+5],rev[N+5];
int res=0;
void add(int &a,int b) {
	a+=b;
	if (a>=mod) a-=mod;
}
long long power(long long a, long long b) {
	long long ans=1;
    while(b){
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
int mul(long long a,long long b) {
	a=(a*b)%mod;
	return a;
}
void prep() {
	gt[0]=1;
	for (int i=1;i<=N;i++)
		gt[i]=mul(gt[i-1],i);
	rev[N]=power(gt[N],mod-2);
	for (int i=N-1;i>=0;i--) rev[i]=mul(rev[i+1],i+1);
}
int c(int k,int n) {
    if(k>n) return 0;
    int ans=mul(rev[k],rev[n-k]);
    ans=mul(ans,gt[n]);
    return ans;
}
int calc(int i) {
	int ans=c(n-i,n-i+m-i);
	ans=mul(ans,c(i,n+m-i));
	return ans;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    prep();
    cin>>n>>m;
    for (int i=0;i<=min(n,m);i++) {
    	add(res,calc(i));
    }
    cout<<res;
}
