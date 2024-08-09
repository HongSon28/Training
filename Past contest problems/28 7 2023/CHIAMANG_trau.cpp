#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
long long a[N+5],sum[N+5];
int main() {
    freopen("CHIAMANG.INP","r",stdin);
    freopen("CHIAMANG.ANS","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    for (int i=1;i<n;i++) {
        long long l=sum[i],r=sum[n]-sum[i];
        if (l==r) {
            cout<<i;
            return 0;
        }
    }
    cout<<0;
}
