#include<bits/stdc++.h>
using namespace std;
string x,y;
int dp[101][101];
int kieu[101],a[101],b[101];
char c[101];
int main() {
    cin>>x>>y;
    int n=x.length(),m=y.length();
    for (int j=1;j<=n;j++) dp[0][j]=j;
    for (int i=0;i<=m;i++) dp[i][0]=i;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (x[j-1]==y[i-1]) {
                dp[i][j]=dp[i-1][j-1];
            } else {
                dp[i][j]=dp[i][j-1]+1;
                if (dp[i][j]>dp[i-1][j]+1) dp[i][j]=dp[i-1][j]+1;
                if (dp[i][j]>dp[i-1][j-1]+1) dp[i][j]=dp[i-1][j-1]+1;
            }
            //cout<<dp[i][j]<<' ';
        }
        //cout<<endl;
    }
    int u=m,v=n,cnt=0;
    while (u>0||v>0) {
        //cout<<u<<' '<<v<<endl;
        if (y[u-1]==x[v-1]) {
            u--;
            v--;
        } else {
            cnt++;
            if (u>=1&&dp[u][v]==dp[u-1][v]+1) {
                a[cnt]=v;
                b[cnt]=u;
                c[cnt]=y[u-1];
                kieu[cnt]=1;
                u--;
            } else if (v>=1&&dp[u][v]==dp[u][v-1]+1) {
                a[cnt]=v;
                b[cnt]=u;
                c[cnt]=y[u-1];
                kieu[cnt]=2;
                v--;
            } else {
                a[cnt]=v;
                b[cnt]=u;
                c[cnt]=y[u-1];
                kieu[cnt]=3;
                u--;
                v--;
            }
        }
    }
    cout<<cnt<<endl;
    for (int i=cnt;i>=1;i--) {
        if (kieu[i]==1) {
            cout<<"I "<<b[i]<<' '<<c[i]<<endl;
        } else if (kieu[i]==2) {
            cout<<"D "<<b[i]+1<<endl;
        } else {
            cout<<"R "<<b[i]<<' '<<c[i]<<endl;
        }
    }
}
