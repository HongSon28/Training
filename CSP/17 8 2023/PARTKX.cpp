#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,k,x;
int mod=10007;
int f[N+5][N+5];
int main() {
    freopen("PARTKX.INP","r",stdin);
    freopen("PARTKX.OUT","w",stdout);
    cin>>n>>k>>x;
    f[0][0]=1;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=k;j++) {
            f[i][j]+=f[i-1][j-1];
            f[i][j]%=mod;
            if (j<=i){
                f[i][j]+=f[i-j][j];
                f[i][j]%=mod;
            }
        }
    }
    cout<<f[n-k*(k-1)/2*x][k];
}
