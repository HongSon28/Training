#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n;
long long x;
long long a[N+5],mn[N+5],sum[N+5];
int mx,lt,rt;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>x;
    for (int i=1;i<=n;i++) {
    	cin>>a[i];
		sum[i]=sum[i-1]+a[i];
    }
    mn[1]=sum[0]-x;
    for (int i=2;i<=n;i++) mn[i]=min(mn[i-1],sum[i-1]-x*i);
    for (int r=1;r<=n;r++) {
    	int l=-1;
    	int lo=1,hi=r;
    	while (lo<=hi) {
    		int mid=(lo+hi)/2;
    		if (sum[r]-x*r-x>=mn[mid]) {
    			l=mid;
    			hi=mid-1;
    		} else lo=mid+1;
    	}
    	if (l!=-1) {
    		if (mx<r-l+1) {
    			mx=r-l+1;
    			lt=l;
    			rt=r;
    		}
    	}
    }
    cout<<mx<<'\n'<<lt<<' '<<rt;
}