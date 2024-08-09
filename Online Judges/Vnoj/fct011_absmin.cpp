#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
int a[N+5];
int res=INT_MAX;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for (int i=2;i<=n;i++)
        res=min(res,abs(a[i-1]-a[i]));
    cout<<res;
}
