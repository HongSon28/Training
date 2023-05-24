#include<bits/stdc++.h>
using namespace std;
int main() {
    unsigned int n;
    cin>>n;
    long long a[n];
    long long total=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    long long m = a[0];
    for (int i=1;i<n;i++) {
        if (a[i]>m) {
            m=a[i];
        }
    }
    cout<<m;
}
