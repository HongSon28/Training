#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,res;
long long a[N+5],sum[N+5];
int f[N+5][N+5];
int main() {
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    f[1][1]=1;
    for (int l=1;l<=n;l++) {
        for (int r=l;r<=n;r++) {
            for (int k=r+1;k<=n;k++) {
                if (sum[k]-sum[r]>=sum[r]-sum[l-1]) f[r+1][k]=max(f[r+1][k],f[l][r]+1);
            }
        }
    }
    for (int l=1;l<=n;l++)
        for (int r=1;r<=n;r++)
            res=max(res,f[l][r]);
    cout<<res;
}
