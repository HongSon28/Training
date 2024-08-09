#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,l,r,a[N+5],dpl[N+5],dpr[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    dpl[1]=1;
    for (int i=2;i<=n;i++) {
        if (a[i]<=a[i-1]) dpl[i]=dpl[i-1];
        else dpl[i]=i;
    }
    dpr[n]=n;
    for (int i=n-1;i>=1;i--) {
        if (a[i]<=a[i+1]) dpr[i]=dpr[i+1];
        else dpr[i]=i;
    }
    while (m--) {
        cin>>l>>r;
        if (dpl[r]<=dpr[l]) cout<<"Yes"<<'\n';
        else cout<<"No"<<'\n';
    }
}
