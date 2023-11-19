#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long a[N+5],mx,sum,res=1e18;
int main() {
    freopen("CSEQ.INP","r",stdin);
    freopen("CSEQ.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) {
        sum+=a[i];
        res=min(res,sum-mx);
        mx=max(mx,sum);
    }
    cout<<sum-2*res;
}
