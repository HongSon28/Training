#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,t;
long long a[N+5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("MAXSEG.INP","r",stdin);
    freopen("MAXSEG.OUT","w",stdout);
    cin>>t;
    while (t--) {
        long long mx=-1e18,sum=0,res=0;
        cin>>n;
        for (int i=1;i<=n;i++) {
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        for (int i=1;i<=n;i++) {
            sum+=a[i];
            if (sum<0) sum=0;
            res=max(res,sum);
        }
        if (res==0) cout<<mx<<'\n';
        else cout<<res<<'\n';
    }
}
