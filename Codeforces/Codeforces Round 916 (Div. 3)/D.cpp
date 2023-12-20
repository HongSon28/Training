#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n;
int a[N+5],b[N+5],c[N+5],x[N+5],y[N+5],z[N+5],xy[N+5],yz[N+5],xz[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		x[i]=max(x[i-1],a[i]);
    	}
    	for (int i=1;i<=n;i++) {
    		cin>>b[i];
    		y[i]=max(y[i-1],b[i]);
    	}
    	for (int i=1;i<=n;i++) {
    		cin>>c[i];
    		z[i]=max(z[i-1],c[i]);
    	}
    	for (int i=2;i<=n;i++) {
    		xy[i]=max({xy[i-1],a[i]+y[i-1],b[i]+x[i-1]});
    		yz[i]=max({yz[i-1],b[i]+z[i-1],c[i]+y[i-1]});
    		xz[i]=max({xz[i-1],a[i]+z[i-1],c[i]+x[i-1]});
    	}
    	int res=0;
    	for (int i=3;i<=n;i++) res=max({res,a[i]+yz[i-1],b[i]+xz[i-1],c[i]+xy[i-1]});
    	cout<<res<<'\n';
    }
}