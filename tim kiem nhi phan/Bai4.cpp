#include<bits/stdc++.h>
using namespace std;
int a[30000];
bool check(int m,int n,int k) {
    int dem=1;
    int box=0;
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
    int n,k;
    cin>>n>>k;
    int mx=0;
    int tong=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
        tong+=a[i];
    }
    int lo=1,hi=tong;
    int mid=lo+(hi-lo)/2;
    while (hi-lo>0) {
        mid=lo+(hi-lo)/2;
        if (check(mid,n,k)==true) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    cout<<lo;
}
