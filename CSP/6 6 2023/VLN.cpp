#include<bits/stdc++.h>
using namespace std;
const int N=100;
long long n,H;
long long a[N+5],sum[N+5];
int main() {
    freopen("VLN.INP","r",stdin);
    freopen("VLN.OUT","w",stdout);
    cin>>n>>H;
    long long num=H/3*2;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    long long res=-1;;
    for (int i=num+1;i<=n;i++) res=max(res,sum[i]-sum[i-num-1]);
    cout<<res;
}
