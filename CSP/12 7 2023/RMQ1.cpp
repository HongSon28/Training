#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
const int MX=20;
int n,m;
int a[N+5];
int rm1[N+5][MX+1],rm2[N+5][MX+1];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("RMQ1.INP","r",stdin);
    freopen("RMQ1.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        rm1[i][0]=a[i];
        rm2[i][0]=a[i];
    }
    for (int j=1;j<=MX;j++) {
        for (int i=1;i<=n-(1<<j)+1;i++) {
            rm1[i][j]=min(rm1[i][j-1],rm1[i+(1<<(j-1))][j-1]);
            rm2[i][j]=max(rm2[i][j-1],rm2[i+(1<<(j-1))][j-1]);
        }
    }
    while (m--) {
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        int k=__lg(len);
        cout<<min(rm1[l][k],rm1[r-(1<<k)+1][k])<<' '<<max(rm2[l][k],rm2[r-(1<<k)+1][k])<<'\n';
    }
}
