#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,x;
    cin>>n>>x;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int lo=0,hi=n-1;
    while (hi-lo>=0) {
        int mid=lo+(hi-lo)/2;
        if (a[mid]<x) {
            lo=mid+1;
        } else if (a[mid]>x) {
            hi=mid-1;
        } else {
            cout<<mid+1;
            return 0;
        }
    }
    cout<<"0";
}
