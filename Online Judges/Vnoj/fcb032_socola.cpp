#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
long long res,mx;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    res=a[n];
    mx=a[n];
    for (int i=n-1;i>=1;i--) {
        long long x=min(a[i],mx-1);
        if (x<=0) break;
        res+=x;
        mx=x;
    }
    cout<<res;
}
