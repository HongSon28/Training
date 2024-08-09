#include<bits/stdc++.h>
using namespace std;
const int N=100,M=2500;
int n,L,R,K;
int a[N+5],sum,res;
int dpl[N+1][N+1][M+1],dpr[N+1][N+1][M+1];
int main() {
    freopen("DEBT.INP","r",stdin);
    freopen("DEBT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>L>>R>>K;
    K=min(K,M);
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=L;i<=R;i++) sum+=a[i];
    for (int i=1;i<L;i++){
        for (int j=1;j<=R-L+1;j++) {
            for (int k=1;k<=K;k++) {
                dpl[i][j][k]=max({0,dpl[i-1][j][k],dpl[i][j-1][k],dpl[i][j][k-1]});
                if (k>=(L+j-1-i)) dpl[i][j][k]=max(dpl[i][j][k],dpl[i-1][j-1][k-(L+j-1-i)]+a[L+j-1]-a[i]);
            }
        }
    }
    for (int i=1;i<n-R+1;i++) {
        for (int j=1;j<=R-L+1;j++) {
            for (int k=1;k<=K;k++) {
                dpr[i][j][k]=max({0,dpr[i-1][j][k],dpr[i][j-1][k],dpr[i][j][k-1]});
                if (k>=(n-i+1-(R-j+1))) dpr[i][j][k]=max(dpr[i][j][k],dpr[i-1][j-1][k-(n-i+1-(R-j+1))]+a[R-j+1]-a[n-i+1]);
                //cout<<i<<' '<<j<<' '<<k<<' '<<R-j+1<<' '<<n-i+1<<' '<<dpr[i][j][k]<<endl;
            }
        }
    }
    for (int i=0;i<=R-L+1;i++){
        for (int t=0;t<=K;t++) {
            res=max(res,dpl[L-1][i][t]+dpr[n-R][R-L+1-i][K-t]);
            //cout<<L-1<<' '<<i<<' '<<t<<' '<<dpl[L-1][i][t]<<endl;
            //cout<<n-R<<' '<<R-L+1-i<<' '<<K-t<<' '<<dpr[n-R][R-L+1-i][K-t]<<endl<<endl;
        }
    }
    cout<<sum-res;
}
