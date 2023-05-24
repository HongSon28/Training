#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,t;
int a[N+1],c[N+1];
void sang() {
    for (int i=0;i<n;i++) {
        for (int j=a[i];j<=t;j+=a[i]) {
            c[j]++;
        }
    }
}
int main() {
    freopen("CNTDUCKS.INP","r",stdin);
    freopen("CNTDUCKS.OUT","w",stdout);
    cin>>n>>t;
    for (int i=0;i<n;i++) cin>>a[i];
    sang();
    int mx=0,cnt=0;
    for (int i=0;i<=t;i++) {
        mx=max(mx,c[i]);
    }
    for (int i=0;i<=t;i++) {
        if (mx==a[i]) cnt++;
    }
    cout<<mx<<' '<<cnt;
}
