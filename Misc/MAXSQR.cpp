#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int m,n,k,a[2005][2005],b[2005][2005],res,c[2005][2005],d[2005][2005];
int cal(int i, int j, int u, int v){
    return c[u][v]-c[i-1][v]-c[u][j-1]+c[i-1][j-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>m>>n>>k;
    while(k--){
        int r1,r2,c1,c2;
        cin>>r1>>c1>>r2>>c2;
        d[r1][c1]++;
        d[r2+1][c2+1]++;
        d[r1][c2+1]--;
        d[r2+1][c1]--;
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) a[i][j]=d[i][j]+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) b[i][j]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==a[i-1][j-1] && a[i][j]==a[i][j-1] && a[i][j]==a[i-1][j]) b[i][j]=0;
            else b[i][j]=1;
            if (b[i][j]) res=0;
        }
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++) c[i][j]=c[i-1][j]+c[i][j-1]-c[i-1][j-1]+b[i][j];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            int l=1,r=min(m,n),mx=0;
            while(l<=r){
                int mid=(l+r)/2;
                int u=i+mid-1,v=j+mid-1;
                if(u<=m && v<=n && !cal(i,j,u,v)){
                    mx=mid;
                    l=mid+1;
                }else r=mid-1;
            }
            res=max(res,mx);
        }
    }
    cout<<res+1;
}