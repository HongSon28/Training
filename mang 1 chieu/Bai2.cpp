#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (unsigned i=0;i<n;i++) {
        cin>>a[i];
    }
    int mx=a[0];
    for (unsigned i=0;i<n;i++) {
        if (a[i]>mx)
            mx=a[i];
    }
    cout<<mx<<endl;
    for (unsigned i=0;i<n;i++) {
        if (mx==a[i]) {
            cout<<i+1<<" ";
        }
    }
}
