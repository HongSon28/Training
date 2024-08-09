#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n,res;
int a[N+5],b[N+5];
bool check(int x) {
    int cnt=0,j=1;
    for (int i=1;i<=n&&j<=x;i++) {
        if (b[i]>a[j]&&b[i]<a[m-(x-j)]) {
            cnt++;
            j++;
        }
    }
    return cnt>=x;
}
int main() {
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m);
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+1+n);
    int lo=0,hi=min(n,m/2);
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res;
}

