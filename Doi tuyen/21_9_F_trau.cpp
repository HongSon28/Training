#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10][10],res;
void rec(int i,int j,int cnt) {
    if (a[i-1][j+1]!=1&&a[i-1][j]!=2&&a[i][j-1]!=2) {
        a[i][j]=1;
        if (i==n&&j==m) res=max(res,cnt+1);
        else if (j==m) rec(i+1,1,cnt+1);
        else rec(i,j+1,cnt+1);
    }
    if (a[i-1][j-1]!=2&&a[i-1][j]!=1&&a[i][j-1]!=1) {
        a[i][j]=2;
        if (i==n&&j==m) res=max(res,cnt+1);
        else if (j==m) rec(i+1,1,cnt+1);
        else rec(i,j+1,cnt+1);
    }
    a[i][j]=0;
    if (i==n&&j==m) res=max(res,cnt);
    else if (j==m) rec(i+1,1,cnt);
    else rec(i,j+1,cnt);
    /*
    if (res==16) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=m;j++) cout<<a[i][j]<<' ';
            cout<<endl;
        }
        exit(0);
    }
    */
}
int main() {
    freopen("21_9_F.INP","r",stdin);
    freopen("21_9_F.ANS","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (cin>>n>>m) {
        res=0;
        rec(1,1,0);
        cout<<res<<'\n';
    }
}
