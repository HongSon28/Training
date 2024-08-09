#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long sum,res,a[N+5],mx;
bool check(long long m) {
    long long cnt=1,cur=0;
    for (int i=1;i<=n;i++) {
        cur+=a[i];
        if (cur>m) {
            cur=a[i];
            cnt++;
        }
    }
    if (cnt>k) return false;
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum+=a[i];
        mx=max(mx,a[i]);
    }
    long long lo=mx,hi=sum;
    while (lo<=hi) {
        long long mid=(lo+hi)/2;
        if (check(mid)) {
            hi=mid-1;
            res=mid;
        } else lo=mid+1;
    }
    cout<<res;
}
