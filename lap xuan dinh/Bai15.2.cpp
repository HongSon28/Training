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
    int hi=5;
    while (lo<hi-1) {
        int mid=lo+(hi-lo)/2;
        if (P(mid,x)) {
            lo=mid;
        } else {
            hi=mid-1;
        }

    }
    return lo;
}
int main() {
    int t;
    cin >>t;
    double x;
    for(int i=0;i<t;i++) {
        cin >> x;
        cout << binarySearch(x) << endl;
    }
}
