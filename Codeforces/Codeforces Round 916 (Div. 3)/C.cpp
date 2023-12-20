#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t,n,k;
int a[N+5],b[N+5],mx[N+5],sum[N+5];
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>t;
    while (t--) {
    	cin>>n>>k;
    	for (int i=1;i<=n;i++) {
    		cin>>a[i];
    		sum[i]=sum[i-1]+a[i];
    	}
    	for (int i=1;i<=n;i++) {
    		cin>>b[i];
    		mx[i]=max(mx[i-1],b[i]);
    	}
    	int res=0;
    	for (int i=1;i<=min(n,k);i++) {
    		res=max(res,sum[i]+mx[i]*(k-i));
    	}
    	cout<<res<<'\n';
    }
}