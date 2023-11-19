#include<bits/stdc++.h>
using namespace std;
int n,m,res;
int a[1001][1001];
int sum[1001][1001];
bool check(int k) {
    for (int i=1;i<=n-k+1;i++) {
        for (int j=1;j<=m-k+1;j++) {
            int i1=i+k-1,j1=j+k-1;
            int t=sum[i1][j1]-sum[i1][j-1]-sum[i-1][j1]+sum[i-1][j-1];
            if (t==k*k) return true;
        }
    }
    return false;
}
int main() {
    cin>>n>>m;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            char t;
            cin>>t;
            if (t=='x') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i==0||j==0) {
                sum[i][j]=0;
            } else {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
            }
        }
    }
    int lo=0,hi=min(n,m);
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)==true) {
            res=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<res*res;
}
