#include<bits/stdc++.h>
using namespace std;
int n,k;
int x[100000];
bool check (int r) {
    int start=x[0];
    int cnt=1;
    for (int i=1;i<n;i++) {
        if (x[i]-start>2*r) {
            cnt++;
            start=x[i];
        }
    }
    if (cnt>k) return false;
    return true;
}
int main() {
    cin>>n>>k;
    for (int i=0;i<n;i++) cin>>x[i];
    sort(x,x+n);
    int lo=1,hi=x[n-1];
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (check(mid)==true) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    cout<<lo;
}
