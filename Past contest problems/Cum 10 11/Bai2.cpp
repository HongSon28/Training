#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int res=0;
    for (int i=0;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (__gcd(a[i],a[j])==1&a[i]>1&&a[j]>1) {
                res++;
            }
        }
    }
    cout<<res;
}
