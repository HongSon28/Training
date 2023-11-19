#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long a[N+5];
long long res=1e18;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=1;i<n;i++) res=min(res,abs(a[i+1]-a[i]));
    cout<<res;
}
