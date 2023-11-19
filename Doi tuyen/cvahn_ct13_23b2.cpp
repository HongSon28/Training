#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[N+5],p[N+5],mn=LLONG_MAX,res;
int n;
int main() {
    freopen("MUAXANG.INP","r",stdin);
    freopen("MUAXANG.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>p[i];
    for (int i=1;i<=n;i++) {
        mn=min(mn,p[i]);
        res+=a[i]*mn;
    }
    cout<<res;
}
