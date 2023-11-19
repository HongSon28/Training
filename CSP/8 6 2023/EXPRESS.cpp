#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k;
long long res;
long long a[N+5];
int main() {
    freopen("EXPRESS.INP","r",stdin);
    freopen("EXPRESS.OUT","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    res=a[1];
    sort(a+2,a+1+n,greater<long long>());
    for (int i=2;i<=k+1;i++) {
        res+=a[i];
    }
    for (int i=k+2;i<=n;i++) res-=a[i];
    cout<<res;
}
