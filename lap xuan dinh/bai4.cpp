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
    sort(a, a+n);
    cout<<a[n-2];
}
