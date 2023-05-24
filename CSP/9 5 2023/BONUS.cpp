#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    int m,n,q;
    cin>>m>>n>>q;
    vector<vector<long long>>a(1e6+5);
    vector<vector<long long>>sum(1e6+5);
    for (int i=1;i<=m;i++) {
        a[i].push_back(0);
        for (int j=1;j<=n;j++) {
            long long temp;
            cin>>temp;
            a[i].push_back(temp);
        }
    }
    for (int i=0;i<=m;i++) {
        for (int j=0;j<=n;j++) {
            sum[i].push_back(0);
            if (i==0||j==0) sum[i][j]=0;
            else sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    while (q--) {
        int x,y,u,v;
        cin>>x>>y>>u>>v;
        cout<<sum[u][v]-sum[x-1][v]-sum[u][y-1]+sum[x-1][y-1]<<endl;
    }
}
