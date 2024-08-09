#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    long long a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    long long mn=0;
    long long mx=0;
    for (int i=0;i<k;i++) {
        mn+=a[i];
    }
    for (int i=n-2;i>n-2-k;i--) {
        mx+=a[i];
    }
    cout<<mn<<" "<<mx;
}

