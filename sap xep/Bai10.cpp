#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int dem=0;
    int lo=0, hi=n-1;
    while (lo!=hi) {
        a[lo]--;
        a[hi-1]+=a[hi];
        if (a[lo]==0)
            lo++;
        hi--;
        dem++;
    }
    cout<<dem;
}
