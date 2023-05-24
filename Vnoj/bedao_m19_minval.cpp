#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int res=__gcd(a[0],a[1]);
    for (int i=1;i<n;i++) res=__gcd(res,a[i]);
    cout<<res;
}
