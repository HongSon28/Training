#include<bits/stdc++.h>
using namespace std;
int main() {
    short n;
    cin>>n;
    unsigned a[n];
    unsigned mx=0;
    for (short i=0;i<n;i++) {
        cin>>a[i];
    }
    for (short i=1;i<n-1;i++) {
        mx=max(mx, a[i+1]-a[i-1]);
    }
    cout<<mx;
}
