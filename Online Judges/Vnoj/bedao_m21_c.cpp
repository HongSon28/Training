#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k,res;
int a[N+5];
bool check(int m) {
    long long cnt=0;
    for (int i=1;i<=n;i++) cnt+=(a[i]-1)/m;
    return cnt<=k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    int lo=1,hi=1e9;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)) {
            res=mid;
            hi=mid-1;
        } else lo=mid+1;
    }
    cout<<res;
}
