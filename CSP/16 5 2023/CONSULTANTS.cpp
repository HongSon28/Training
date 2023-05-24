#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m;
long long a[N+5];
bool check(long long k) {
    long long res=0;
    for (int i=1;i<=n;i++) res+=k/a[i];
    if (res>=m) return true;
    return false;
}
int main() {
    freopen("CONSULTANTS.INP","r",stdin);
    freopen("CONSULTANTS.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    long long lo=0,hi=1e15;
    while (lo<hi) {
        long long mid=(lo+hi)/2;
        if (check(mid)) hi=mid;
        else lo=mid+1;
    }
    cout<<lo;
}
