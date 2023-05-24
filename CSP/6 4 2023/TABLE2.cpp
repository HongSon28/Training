#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long mn=INT_MAX,mx=INT_MIN;
long long a[1001][1001];
long long b[1001][1001];
long long sum[1001][1001];
bool check(int v) {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            if (a[i][j]>=v) b[i][j]=1;
            else b[i][j]=0;
        }
    }
    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (i==0||j==0) {
                sum[i][j]=0;
            } else {
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+b[i][j];
            }
        }
    }
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TABLE2.INP","r",stdin);
    freopen("TABLE2.OUT","w",stdout);
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cin>>a[i][j];
            mn=min(mn,a[i][j]);
            mx=max(mx,a[i][j]);
        }
    }
    int lo=mn,hi=mx,res=INT_MIN;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (check(mid)==true) {
            res=max(res,mid);
            lo=mid+1;
        }
        else hi=mid-1;
    }
    cout<<res;
}
