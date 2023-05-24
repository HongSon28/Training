#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int a[n+1][m+1];
    int sum[n+1][m+1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            cin>>a[i][j];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i==0||j==0) {
                sum[i][j]=0;
            } else {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
            }
        }
    }
    int res=INT_MAX;
    for (int i=1;i<n;i++) {
        for (int j=1;j<m;j++) {
            int sum1=sum[i][j];
            int sum2=sum[n][j]-sum1;
            int sum3=sum[i][m]-sum1;
            int sum4=sum[n][m]-sum1-sum2-sum3;
            int mx=max(max(max(sum1,sum2),sum3),sum4);
            int mn=min(min(min(sum1,sum2),sum3),sum4);
            res=min(res,mx-mn);
        }
    }
    cout<<res;
}
