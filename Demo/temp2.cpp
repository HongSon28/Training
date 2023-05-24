#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,s;
    cin>>n>>s;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int dem=0;
    for (int i=0;i<n;i++) {
        if (a[i]<=s) {
            dem++;
            s+=a[i];
        } else {
            break;
        }
    }
    cout<<dem;
}

