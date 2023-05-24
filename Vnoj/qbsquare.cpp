#include<bits/stdc++.h>
using namespace std;
const int N=1e3;
int a[N+5][N+5];
int sum[N+5][N+5];
int m,n;
bool check(int k) {
    for (int i=1;i<=m-k+1;i++) {
        for (int j=1;j<=n-k+1;j++) {
            int u=i+k-1,v=j+k-1;
            int s=sum[u][v]-sum[u][j-1]-sum[i-1][v]+sum[i-1][j-1];
            if (s==0||s==k*k) return true;
        }
    }
    return false;
}
int main() {
    cin>>m>>n;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=0;i<=m;i++) {
        for (int j=0;j<=n;j++) {
            if (i==0||j==0) sum[i][j]=0;
            else sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    int lo=1,hi=min(m,n);
    while (lo<hi) {
        int mid=(lo+hi+1)/2;
        if (check(mid)) lo=mid;
        else hi=mid-1;
    }
    cout<<lo;
}
