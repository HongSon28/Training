#include<bits/stdc++.h>
using namespace std;
const int N=5e3;
int n,t,q;
int a[N+5][N+5];
int hor[N+5][N+5],ver[N+5][N+5];
int main() {
    freopen("ITABLE.INP","r",stdin);
    freopen("ITABLE.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>t;
    while (t--) {
        int k,rc,x,y;
        cin>>k>>rc>>x>>y;
        if (k==1) {
            int u=(y-x+1+1)/2,v=(y-x+1+2)/2;
            hor[rc][x]++;
            hor[rc][x+u]--;
            hor[rc][x+v]--;
            hor[rc][y+2]++;
        } else {
            int u=(y-x+1+1)/2,v=(y-x+1+2)/2;
            ver[x][rc]++;
            ver[x+u][rc]--;
            ver[x+v][rc]--;
            ver[y+2][rc]++;
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            hor[i][j]+=hor[i][j - 1];
            ver[i][j]+=ver[i - 1][j];
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            hor[i][j]+=hor[i][j - 1];
            ver[i][j]+=ver[i - 1][j];
        }
    }
    cin>>q;
    while (q--) {
        int x,y;
        cin>>x>>y;
        cout<<hor[x][y]+ver[x][y]<<'\n';
    }
}
