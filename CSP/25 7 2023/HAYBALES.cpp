#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
int a[N+5];
int l,r;
int main() {
    freopen("HAYBALES.INP","r",stdin);
    freopen("HAYBALES.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    while (m--) {
        cin>>l>>r;
        int lo=1,hi=n;
        int res1=0,res2=0;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (a[mid]>=l) {
                res1=mid;
                hi=mid-1;
            } else lo=mid+1;
        }
        lo=1,hi=n;
        while (lo<=hi) {
            int mid=(lo+hi)/2;
            if (a[mid]<=r) {
                res2=mid;
                lo=mid+1;
            } else hi=mid-1;
        }
        if (res1==0||res2==0) cout<<0<<endl;
        else cout<<res2-res1+1<<endl;
    }
}
