#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("MMAX.INP","r",stdin);
    freopen("MMAX.OUT","w",stdout);
    int n;
    cin>>n;
    long long a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long res=INT_MIN;
    res=max(res,a[0]*a[1]);
    res=max(res,a[0]*a[1]*a[2]);
    res=max(res,a[n-1]*a[n-2]);
    res=max(res,a[n-3]*a[n-2]*a[n-1]);
    res=max(res,a[n-3]*a[n-2]);
    res=max(res,a[0]*a[1]*a[n-1]);
    cout<<res;
}
