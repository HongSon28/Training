#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000];
bool check(long long k) {
    long long tong=0;
    for (int i=0;i<n;i++) {
        if (a[i]>k)
            tong+=a[i]-k;
    }
    if (tong>=m) {
        return true;
    }
    return false;
}
int main() {
    cin>>n>>m;
    long long mx=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    long long lo=1,hi=mx;
    while (hi-lo>0) {
        long long mid=lo+(hi-lo+1)/2;
        if (check(mid)==true) {
            lo=mid;
        } else {
            hi=mid-1;
        }
    }
    cout<<lo;
}
