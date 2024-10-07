#include<bits/stdc++.h>
using namespace std;
const int N=2e5,LG=__lg(N);
int t,n;
long long a[N+5],d[N+5];
long long g[N+5][LG+5];
bool check(int l,int r) {
	int t=__lg(r-l+1);
	long long temp=__gcd(g[l][t],g[r-(1<<t)+1][t]);
	return (temp>1);
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) cin>>a[i];
    	for (int i=1;i<n;i++) {
    		d[i]=abs(a[i]-a[i+1]);
    		g[i][0]=d[i];
    	}
    	for (int i=1;i<=LG;i++) {
    		for (int j=1;j+(1<<i)-1<=n;j++)
    			g[j][i]=__gcd(g[j][i-1],g[j+(1<<(i-1))][i-1]); 
    	}
    	int r=1,res=1;
    	for (int l=1;l<=n;l++) {
    		r=max(r,l);
    		while (r<n&&check(l,r)) r++;
    		res=max(res,r-l+1); 
    	}
    	cout<<res<<'\n';
    }
}