#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n,res;
int a[N+5],b[N+5];
bool check(int x) {
    int cnt=0,j=1;
    for (int i=1;i<=m&&j<=x;i++) {
        if (a[i]>b[j]&&a[i]<b[n-(x-j)]) {
            cnt++;
            j++;
        }
    }
    return cnt>=x;
}
int main() {
    freopen("BALL.INP","r",stdin);
    freopen("BALL.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n;
    for (int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+m);
    for (int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+1+n);
    int lo=0,hi=min(m,n/2);
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            lo=mid+1;
        } else hi=mid-1;
    }
    cout<<res;
}
