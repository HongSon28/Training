#include<bits/stdc++.h>
using namespace std;
int n,s;
int a[1000000];
long long sum[1000000];
bool check(int m) {
    long long tong;
    for (int i=0;i<n-m;i++) {
        if (i==0) {
            tong=sum[m];
        } else {
            tong=sum[i+m]-sum[i];
        }
        if (tong>=s)
            return true;
    }
    return false;
}
int main () {
    cin>>n>>s;
    sum[0]=a[0];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<n;i++) {
        sum[i]=sum[i-1]+a[i];
    }
    int lo=1,hi=n;
    while (hi-lo>0) {
        int mid=lo+(hi-lo)/2;
        if (check(mid)==true) {
            hi=mid;
        } else {
            lo=mid+1;
        }
    }
    cout<<lo;
}

