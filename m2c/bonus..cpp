#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n+1][n+1];
    int sum[n+1][n+1];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=n;j++) {
            if (i==0||j==0) {
                sum[i][j]=0;
            } else {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
            }
        }
    }
    int res=INT_MIN;
    for (int i=1;i<=n-k+1;i++) {
        for (int j=1;j<=n-k+1;j++) {
            int i1=i+k-1,j1=j+k-1;
            int t=sum[i1][j1]-sum[i1][j-1]-sum[i-1][j1]+sum[i-1][j-1];
            res=max(res,t);
        }
    }
    cout<<res;
}
