#include<bits/stdc++.h>
using namespace std;
int a[100000];
bool check(int b, int m) {
    int lo=0,hi=m-1;
    while(hi-lo>=0) {
        int mid=lo+(hi-lo)/2;
        if (a[mid]>b) {
            hi=mid-1;
        } else if (a[mid]<b) {
            lo=mid+1;
        } else {
            return true;
        }
    }
    return false;
}
int main() {
    int m;
    cin>>m;
    for (int i=0;i<m;i++) {
        cin>>a[i];
    }
    int n;
    int dem=0;
    cin>>n;
    int b[n];
    for (int i=0;i<n;i++) {
        cin>>b[i];
    }
    sort(a,a+m);
    for (int i=0;i<n;i++) {
        if (check(b[i],m)==true) {
            dem++;
        }
    }
    cout<<dem;
}
