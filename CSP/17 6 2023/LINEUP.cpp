#include<bits/stdc++.h>
using namespace std;
const int N=3e6;
int n;
long long res=1;
long long mod=1e9+7;
long long a[N+5];
long long b[N+5];
long long f[N+5];
long long sum[N+5];
stack<long long>st;
int main() {
    freopen("LINEUP.INP","r",stdin);
    freopen("LINEUP.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=n;i>=1;i--) {
        while (!st.empty()&&a[st.top()]<=a[i]) st.pop();
        if (st.empty()) b[i]=n+1;
        else b[i]=st.top();
        st.push(i);
    }
    f[n]=f[n+1]=1;
    sum[n+1]=f[n+1];
    sum[n]=f[n]+f[n+1];
    for (int i=n-1;i>=1;i--) {
        int l=i+1,r=b[i];
        f[i]=(sum[l]-sum[r+1]+mod)%mod;
        sum[i]=(sum[i+1]+f[i])%mod;
    }
//    for (int i=1;i<=n;i++) cout<<b[i]<<' ';
//    cout<<endl;
//    for (int i=1;i<=n;i++) cout<<f[i]<<' ';
    cout<<f[1];
}
