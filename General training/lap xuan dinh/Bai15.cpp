#include <bits/stdc++.h>
using namespace std;
bool P(int n, float x) {
    double tong=0;
    for (int j=1;j<=n;j++) {
        tong=tong+(double)1/(2*j-1);
    }
    if (tong<x) {
        return true;
    } else {
        return false;
    }
}
int binarySearch(float x) {
    int lo=1;
    int hi=1000000;
    while (lo<hi) {
        int mid=lo+(hi-lo)/2;
        if (P(mid,x)==true) {
            lo=mid;
        } else {
            hi=mid-1;
        }

    }
    return lo;
}
int main() {
    int t;
    cin>>t;
    float x[t];
    for (int a=0;a<t;a++) {
        cin>>x[a];
    }
    for (int a=0;a<t;a++) {
        cout<<binarySearch(x[a])<<endl;
    }
}
