#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5;
int n;
ll m,res;
ll a[N+5],sum[N+5];
bool check(int i,int md) {
    if (sum[md]-sum[i-1]<=m) return true;
    return false;
}
int main() {
    freopen("C.inp","r",stdin);
    freopen("C.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        if (a[i]>m) continue;
        int lo=i,hi=n;
        while (lo<hi) {
            int mid=(lo+hi+1)/2;
            if (check(i,mid)==true) lo=mid;
            else hi=mid-1;
        }
        res+=lo-i+1;
    }
    cout<<res;
}
