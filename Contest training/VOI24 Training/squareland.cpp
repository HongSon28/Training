#include<bits/stdc++.h>
using namespace std;
const int N=3e3;
int w,h,n,c;
int a[N+5][N+5],b[N+5][N+5],sum[N+5][N+5];
int res=INT_MAX;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>w>>h>>n>>c;
    for (int i=1;i<=n;i++) {
        int x,y;
        cin>>x>>y;
        x++;
        y++;
        a[x][y]=1;
    }
    for (int i=1;i<=w+1;i++) {
        for (int j=1;j<=h+1;j++) {
            int u=i-j+h+1;
            int v=i+j;
            b[u][v]=a[i][j];
            //cout<<a[i][j]<<' ';
        }
        //cout<<endl;
    }
    for (int i=1;i<=w+h+1;i++) {
        for (int j=1;j<=w+h+2;j++) {
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
            //cout<<b[i][j]<<' ';
        }
        //cout<<endl;
    }
    for (int i=c+1;i+c<=w+1;i++) {
        for (int j=c+1;j+c<=h+1;j++) {
            int u=i-j+h+1,v=i+j;
            int u1=max(u-c,1),v1=max(v-c,1);
            int u2=min(u+c,w+h+1),v2=min(v+c,w+h+2);
            res=min(res,sum[u2][v2]-sum[u2][v1-1]-sum[u1-1][v2]+sum[u1-1][v1-1]);
            //cout<<i<<' '<<j<<' '<<u<<' '<<v<<' '<<sum[u2][v2]-sum[u2][v1-1]-sum[u1-1][v2]+sum[u1-1][v1-1]<<endl;
        }
    }
    cout<<res;
}
