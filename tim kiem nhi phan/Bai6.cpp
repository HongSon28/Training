#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    long long dem=0;
    sort(a,a+n);
    for (int i=n-1;i>=1;i--) {
        int lo=0, hi=i-1;
        while (hi>lo) {
            if (a[hi]+a[lo]>a[i]) {
                dem+=hi-lo;
                hi--;
            } else {
                lo++;
            }
        }
    }
    cout<<dem;
}
