#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned n;
    cin>>n;
    unsigned a[n];
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
    }
    unsigned tong=0;
    for (unsigned i=0;i<n;i++) {
        tong+=a[i];
    }
    if (tong%2==0)
        cout<<"YES";
    else
        cout<<"NO";
}
