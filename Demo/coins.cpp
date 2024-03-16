#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,a[N+5],b[N+5],f[N+5],res,k,inf=1e9;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=k;i++) f[i]=inf;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) {
        for(int j=1;j<=n;j++) {
        	if (i>=a[j]) f[i]=min(f[i],f[i-a[j]]+1);
    	}
    }
    if(f[k]==inf) cout<<-1;
    else cout<<f[k];
}