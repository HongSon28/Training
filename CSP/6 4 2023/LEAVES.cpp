#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,s,res1,res2;
long long a[N+5],b[N+5];
bool check(long long k) {
    long long sum=0;
    for (int i=1;i<=n;i++) b[i]=a[i]+i*k;
    sort(b+1,b+1+n);
    for (int i=1;i<=k;i++) sum+=b[i];
    if (sum<=s) {
        res2=sum;
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    cin>>n>>s;
    for (int i=1;i<=n;i++) cin>>a[i];
    int lo=0,hi=n;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        if (check(mid)==true) {
            lo=mid+1;
            res1=mid;
        } else {
            hi=mid-1;
        }
    }
    if (lo!=0)
        cout<<res1<<' '<<res2;
    else
        cout<<res1;
}
