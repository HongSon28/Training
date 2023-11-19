#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,k;
long long a[N+5];
long long res;
long long l,r;
bool check(long long m) {
    long long cnt=1,cur=0;
    for (int i=1;i<=n;i++) {
        cur+=a[i];
        if (cur>m) {
            cur=a[i];
            cnt++;
        }
    }
    if (cnt<=k) return true;
    return false;
}
int main() {
    freopen("MEMORIES.INP","r",stdin);
    freopen("MEMORIES.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        l=max(l,a[i]);
        r+=a[i];
    }
    while (l<=r) {
        long long mid=(l+r)/2;
        if (check(mid)) {
            res=mid;
            r=mid-1;
        } else l=mid+1;
    }
    cout<<res;
}
