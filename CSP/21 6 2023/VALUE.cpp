#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t;
long long n;
long long a[N+5];
long long l[N+5],r[N+5];
int main() {
    freopen("VALUE.INP","r",stdin);
    freopen("VALUE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        cin>>n;
        long long res=-1e18;
        for (long long i=1;i<=n;i++) {
            cin>>a[i];
            l[i]=r[i]=0;
        }
        l[0]=-1e18,r[n+1]=-1e18;
        for (long long i=1;i<=n;i++) l[i]=max(l[i-1],a[i]+i-1);
        for (long long i=n;i>=1;i--) r[i]=max(r[i+1],a[i]+n-i);
        for (long long i=2;i<n;i++) {
            res=max(res,l[i-1]+a[i]+r[i+1]);
        }
        cout<<res-n<<endl;
    }
}
