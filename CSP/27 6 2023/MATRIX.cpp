#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500;
int m,n;
ll a[N+5][N+5];
ll sum[N+5][N+5];
ll res=-1e18;
ll kadane(int left,int right) {
    ll t=0,s=0;
    for (int i=1;i<=m;i++) {
        ll temp=sum[i][right]-sum[i][left-1];
        s+=temp;
        if (s<0) s=0;
        t=max(s,t);
    }
    return t;
}
int main() {
    freopen("MATRIX.INP","r",stdin);
    freopen("MATRIX.OUT","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>a[i][j];
            sum[i][j]=sum[i][j-1]+a[i][j];
        }
    }
    for (int left=1;left<=n;left++) {
        for (int right=left;right<=n;right++) {
            res=max(res,kadane(left,right));
        }
    }
    cout<<res;
}
