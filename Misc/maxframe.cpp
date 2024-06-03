#include <bits/stdc++.h>
using namespace std;
const int N=400;
int m,n;
int a[N+5][N+5],col[N+5][N+5],row[N+5][N+5];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
            col[i][j]=col[i-1][j]+a[i][j];
            row[i][j]=row[i][j-1]+a[i][j];
        }
    }
    int mx=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int u=1;
            int mn=row[i][u-1]+row[j][u-1]-col[j-1][u]+col[i][u];
            for(int v=2;v<=m;v++){
                mx=max(mx,row[i][v]+row[j][v]+col[j-1][v]-col[i][v]-mn);
                u=v-1;
                mn=min(mn,row[i][u-1]+row[j][u-1]-col[j-1][u]+col[i][u]);
            }
        }
    }
    cout<<mx;
}