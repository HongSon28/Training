#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,m;
long long a[N+5];
long long res;
int main() {
    freopen("BAI3.INP","r",stdin);
    freopen("BAI3.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<=n;i++) {
        int j=upper_bound(a+1,a+1+n,m-a[i])-a;
        j--;
        if (i==j) j--;
        if (j==0) continue;
        res=max(res,a[i]+a[j]);
    }
    cout<<res;
}
