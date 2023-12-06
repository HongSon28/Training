#include<bits/stdc++.h>
using namespace std;
int a[30000];
bool check(int k,int n,int kq) {
    int dem=0;
    for (int i=0;i<n;i++) {
        dem+=a[i]/k;
    }
    return dem>=kq;
}
int main() {
    int n,k;
    int mx=0;
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    int lo=1,hi=mx;
    while (hi-lo>=0) {
        int mid=lo+(hi-lo)/2;
        if (check(mid,n,k)==true) {
            lo=mid+1;
        } else {
            hi=mid-1;
        }
    }
    cout<<lo-1;
}
