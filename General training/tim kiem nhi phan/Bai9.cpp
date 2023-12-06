#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n;
bool check(int m) {
    int vt=0;
    for (int i=1;i<n;i++) {
        if (a[i]-a[vt]<=m&&a[i]-a[vt]>=0)
            vt=i;
    }
    if (a[vt]>=a[n-1])
        return true;
    else
        return false;
}
int main() {
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int lo=0, hi=a[n-1]-a[0];
    while (hi>lo) {
        int mid=lo+(hi-lo)/2;
        if (check(mid)==true) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    cout<<lo;
}
