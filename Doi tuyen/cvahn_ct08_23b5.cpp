#include<bits/stdc++.h>
using namespace std;
const int N=100;
int m,n,t,res;
int a[N+5][N+5];
bool vis[N+5][N+5];
int main() {
    freopen("DICHUYENCAY.INP","r",stdin);
    freopen("DICHUYENCAY.OUT","w",stdout);
    cin>>m>>n>>t;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++) {
        int cnt=1;
        for (int j=1;j<=n;j++) {
            if (a[i][j+1]==a[i][j]) cnt++;
            else {
                if (cnt>=t) {
                    for (int k=j;k>=j-cnt+1;k--) vis[i][k]=true;
                    //cout<<i<<' '<<j<<' '<<cnt<<endl;
                }

                cnt=1;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        int cnt=1;
        for (int j=1;j<=m;j++) {
            if (a[j+1][i]==a[j][i]) cnt++;
            else {
                if (cnt>=t) {
                    for (int k=j;k>=j-cnt+1;k--) vis[k][i]=true;
                    //cout<<j<<' '<<i<<' '<<cnt<<endl;
                }
                cnt=1;
            }
        }
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            if (!vis[i][j]&&a[i][j]!=0) res++;
    cout<<res;
}
/*
5 6 3
1 3 3 3 3 4
1 2 3 2 0 4
3 2 2 2 4 4
1 0 0 2 4 0
1 2 3 0 4 4
*/
