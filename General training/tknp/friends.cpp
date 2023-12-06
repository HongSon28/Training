#include<bits/stdc++.h>
using namespace std;
int a[100000];
int timnp(int lo, int hi, int t, int i) {
    int dem=0;
    while (hi>=lo) {
        int mid=lo+(hi-lo)/2;
        if (a[mid]>t) {
            hi=mid-1;
        } else if (a[mid]<t) {
            lo=mid+1;
        } else {
            dem++;
            int l=mid-1,r=mid+1;
            while (a[l]==t&&l>i) {
                dem++;
                l--;
            }
            while (a[r]==t) {
                dem++;
                r++;
            }
            return dem;
        }
    }
    return dem;
}
int main() {
    int n,b;
    cin>>n>>b;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int dem=0;
    for (int i=0;i<n-2;i++) {
        int lo=i+1,hi=n-1;
        int tim=b-a[i];
        dem+=timnp(lo,hi,tim,i);
    }
    if (a[n-2]+a[n-1]==b) {
        dem++;
    }
    cout<<dem;
}

