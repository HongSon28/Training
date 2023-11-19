#include<bits/stdc++.h>
using namespace std;
const int N=300;
int m,n;
int a[N+5][N+5];
int h[N+5];
int res[N+5][N+5];
int ans[N+5][N+5];
int main() {
    freopen("RECT.INP","r",stdin);
    freopen("RECT.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (a[i][j]==0) h[j]++;
            else h[j]=0;
        }
        for (int r=1;r<=n;r++) {
            int cur=h[r];
            for (int l=r;l>=1;l--) {
                cur=min(cur,h[l]);
                res[cur][r-l+1]++;
            }
        }
    }
    for (int j=1;j<=n;j++) {
        int cur=0;
        for (int i=m;i>=1;i--) {
            cur+=res[i][j];
            ans[i][j]=cur;
        }
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++) cout<<ans[i][j]<<' ';
        cout<<endl;
    }
}
