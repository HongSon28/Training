#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long x[N+5],y[N+5],mod=1e9+7;
long long s1,s2,cur;
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);	
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>x[i];
    for (int i=1;i<=m;i++) cin>>y[i];
    for (int i=1;i<=n;i++) {
    	s1+=(x[i]*(i-1)%mod-cur)%mod;
    	s1=(s1%mod+mod)%mod;
    	cur+=x[i];
    	cur%=mod;
    }
    cur=0;
    for (int i=1;i<=m;i++) {
    	s2+=(y[i]*(i-1)%mod-cur)%mod;
    	s2=(s2%mod+mod)%mod;
    	cur+=y[i];
    	cur%=mod;
    }
    cout<<s1*s2%mod;
}