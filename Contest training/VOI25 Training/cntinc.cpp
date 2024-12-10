#include<bits/stdc++.h>
using namespace std;
const int N=2e5,M=710;
int n;
long long f[N+5],g[N+5],mod=1e9,res;
void add(long long &x,long long y) {
	x+=y;
	if (x>=mod) x-=mod;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    g[0]=1;
    for (int i=1;i<=710;i++) {
    	for (int j=0;j<=n;j++) f[j]=0;
    	for (int j=i;j<=n;j++) {
    		add(f[j],g[j-i]);
    		add(f[j],f[j-i]);
    	}
    	for (int j=0;j<=n;j++) g[j]=f[j];
    	add(res,f[n]);
    }
	cout<<res;
}