#include<bits/stdc++.h>
using namespace std;
int bcnn(int a,int b) {
    return a*b/__gcd(a,b);
}
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) {
        cin>>a[i];
    }
    int dem=0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (a[i]%2==a[j]%2) {
                if (a[i]+a[j]==2*bcnn(a[i],a[j])) {
                    dem++;
                }
            }
        }
    }
    cout<<dem;
}
