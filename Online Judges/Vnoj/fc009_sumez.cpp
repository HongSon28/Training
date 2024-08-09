#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,l,r;
long long a[N+5],sum[N+5];
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    while (m--) {
        cin>>l>>r;
        cout<<sum[r]-sum[l-1]<<endl;
    }
}
