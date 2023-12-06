#include<bits/stdc++.h>
using namespace std;
int n,res=0;
int a[1001], b[1001], c[1001];
int tknp1 (int m) {
    int lo=1,hi=n;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (c[mid]>m) hi=mid;
        else lo=mid+1;
    }
    return lo;
}
int tknp2 (int m) {
    int lo=1,hi=n;
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (c[mid]<m) lo=mid;
        else hi=mid-1;
    }
    return lo;
}
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++) cin>>c[i];
    sort(c+1,c+1+n);
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i]+b[j]>c[1]&&abs(a[i]-b[j])<c[n]) {
                int l=tknp1(abs(a[i]-b[j]));
                int r=tknp2(a[i]+b[j]);
                if (l<=r) {
                    res+=r-l+1;
                }
            }
        }
    }
    cout<<res;
}
