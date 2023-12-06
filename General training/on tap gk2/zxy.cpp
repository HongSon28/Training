#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
long long n,k;
bool check(long long m) {
    long long dem=1;
    long long box=0;
    for (int i=0;i<n;i++) {
        if (box+a[i]<=m) {
            box+=a[i];
        } else {
            dem++;
            box=a[i];
        }
    }
    if (dem<=k)
        return true;
    return false;
}
int main() {
    //freopen("ZXY.inp","r",stdin);
    //freopen("ZXY.out","w",stdout);
    cin>>n>>k;
    long long tong=0;
    long long mx=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        tong+=a[i];
        mx=max(mx,a[i]);
    }
    long long lo=mx,hi=tong;
    long long mid;
    while (hi-lo>0) {
        mid=(lo+hi)/2;
        if (check(mid)==true) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    cout<<lo;
}

