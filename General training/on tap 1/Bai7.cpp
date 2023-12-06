#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k,dem=0;
    cin>>n>>k;
    int a[n+1]={};
    for (int i=1;i<=n;i++) {
        for (int j=i;j<=n;j+=i) {
            a[j]++;
        }
    }
    for (int i=1;i<=n;i++) {
        if (a[i]==k)
            dem++;
    }
    cout<<dem;
}
