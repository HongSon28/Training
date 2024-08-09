#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned n,k;
    cin>>n>>k;
    long long a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    unsigned long long mn=0;
    unsigned long long mx=0;
    for (unsigned i=0;i<k;i++) {
        mn+=a[i];
    }
    for (unsigned i=n-2;i>n-2-k;i--) {
        mx+=a[i];
    }
    cout<<mn<<" "<<mx;
}
