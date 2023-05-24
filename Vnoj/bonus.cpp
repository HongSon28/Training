#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int a[n][n];
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin>>a[i][j];
        }
    }
    long long sum[n+1][n+1];
    for (int i=0;i<n+1;i++) {
        for (int j=0;j<n+1;j++) {
            if ((i==0)||(j==0)) {
                sum[i][j]=0;
            } else {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i-1][j-1];
            }
        }
    }
    int mx=INT_MIN;
    for (int i=0;i<=n-k;i++) {
        for (int j=0;j<=n-k;j++) {
            int tong=sum[i+k][j+k]-sum[i+k][j]-sum[i][j+k]+sum[i][j];
            mx=max(mx,tong);
        }
    }
    cout<<mx;
}
