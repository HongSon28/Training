#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long a[N+5],c[N+5],cnt[N+5];
long long mod=1e9+9,ans[N+5];
long long pw(long long x) {
	if (x==0) return 1;
	if (x==1) return m%mod;
	long long res=pw(x/2);
	res=(res*res)%mod;
	if (x%2==1) res=(res*m)%mod;
	return res;
}
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (long long i=1;i<=n;i++) {
    	cin>>a[i];
    	if (a[i]==0) c[0]++;
    	else {
    		for (long long j=1;j*j<=a[i];j++) {
    			if (a[i]%j==0) {
    				if (j*j<a[i]) {
    					cnt[j]++;
    					cnt[a[i]/j]++;
    				} else cnt[j]++;
    			}
    		}
    	}
    }
    for (int i=1;i<=m;i++) {
    	ans[i]=c[0]*(c[0]-1)/2%mod*(m/i)%mod*(m/i)%mod*pw(c[0]-2)%mod
              +c[0]*(m/i)%mod*pw(c[0]-1)%mod*cnt[i]%mod
              +cnt[i]*(cnt[i]-1)/2%mod*pw(c[0])%mod;
        ans[i]%=mod;
    }
    for (int i=m;i>=1;i--) {
    	for (int j=i*2;j<=m;j+=i) {
    		ans[i]-=ans[j];
    		ans[i]=(ans[i]+mod)%mod;
    	}
    }
    cout<<ans[1];
}