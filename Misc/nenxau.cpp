#include<bits/stdc++.h>
using namespace std;
int main() {
    string a;
    cin>>a;
    int n=a.length();
    for (int j=0;j<n;j++) {
        if (a[j]>=65&&a[j]<=90)
            a[j]+=32;
    }
    for (int j=0;j<n;j++) {
        int dem=1;
        while (j<n-1&&a[j]==a[j+1]) {
            dem++;
            j++;
        }
        if (dem==1) {
            cout<<a[j];
        } else if (dem==2) {
            cout<<a[j]<<a[j];
        } else {
            cout<<dem<<a[j];
        }
    }
}

