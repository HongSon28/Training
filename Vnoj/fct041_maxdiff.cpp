#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
long long a[N+5];
long long pre[N+5],suf[N+5];
long long res;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    pre[0]=pre[1]=-1e18;
    for (int i=2;i<=n;i++) pre[i]=max(suf[i-1],a[i]-a[i-1]);
    suf[n+1]=suf[n]=-1e18;
    for (int i=n-1;i>=1;i--) suf[i]=max(suf[i+1],a[i+1]-a[i]);
    res=max(pre[n-1],suf[2]);
    for (int i=2;i<n;i++) res=max(res,max({pre[i-1],suf[i+1],a[i+1]-a[i-1]}));
    cout<<res;
}
