#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e6;
long long a[N+5];
long long res;
long long mod=846103811092001;
long long calc (int l, int r) {
    return ((r-l+1)*(r+l)/2)%mod;
}
int l[N+5],r[N+5];
stack<int>st;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("VALARRAY.INP","r",stdin);
    //freopen("VALARRAY.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        while (!st.empty()&&a[st.top()]<=a[i]) st.pop();
        if (st.empty()) l[i]=1;
        else l[i]=st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i=n;i>=1;i--) {
        while (!st.empty()&&a[st.top()]<a[i]) st.pop();
        if (st.empty()) r[i]=n;
        else r[i]=st.top();
        st.push(i);
    }
    for (int i=1;i<=n;i++) {
        res+=a[i]*(calc(i,r[i]-1)*(i-l[i])%mod-(i-calc(l[i]+1,i-1))*(r[i]-i)%mod+(r[i]-i)*(i-l[i])%mod)%mod;
        cout<<l[i]<<' '<<r[i]<<' '<<(calc(i,r[i]-1)*(i-l[i])%mod-(i-calc(l[i]+1,i-1))*(r[i]-i)%mod+(r[i]-i)*(i-l[i])%mod)%mod<<endl;
        res%=mod;
    }
    cout<<res;
}
