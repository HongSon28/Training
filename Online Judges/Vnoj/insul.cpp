#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    long long a[n];
    long long res=0;
    for (int i=0;i<n;i++) {
        cin>>a[i];
        res+=a[i];
    }
    sort(a,a+n);
    int r=n-1,l=0;
    for (int i=0;i<n;i++) {
        int j=n-i-1;
        if (i>=j) break;
        res+=a[j]-a[i];
    }
    cout<<res;
}
