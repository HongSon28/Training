#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned n;
    cin>>n;
    unsigned a[n];
    unsigned kq=n-1;
    unsigned kt=0;
    for (unsigned i=0; i<n; i++) {
        cin>>a[i];
    }
    for (unsigned i=0; i<n-1; i++) {
        for (unsigned j=i+1;j<n;j++) {
            if (a[i]==a[j]) {
                kq=min(j-i,kq);
                kt+=1;
            }
        }
    }
    if (kt>=1) {
        cout<<kq;
    } else {
        cout<<"-1";
    }
}
