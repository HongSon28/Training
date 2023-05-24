#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned n, k;
    cin>>n>>k;
    short a[n];
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
    }
    int dem=0;
    for (unsigned i=0;i<n-1;i++) {
        for (unsigned j=1;j<n;j++) {
            if (a[i]+a[j]*a[j]==k)
                dem+=1;
        }
    }
    cout<<dem;
}
