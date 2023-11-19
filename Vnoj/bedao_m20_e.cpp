#include<bits/stdc++.h>
using namespace std;
const int N=400;
int n;
long long a[N+5],b[N+5],sa[N+5],sb[N+5];
long long c[N+5][N+5],sum[N+5][N+5];
long long res=LLONG_MIN;
long long getsum(int l,int r,int u,int v) {
    return sum[l][r]-sum[l][v-1]-sum[u-1][r]+sum[u-1][v-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sa[i]=sa[i-1]+a[i];
    }
    for (int i=1;i<=n;i++) {
        cin>>b[i];
        sb[i]=sb[i-1]+b[i];
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i<=j) c[i][j]=sa[j]-sa[i-1];
            else c[i][j]=sb[i]-sb[j-1];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+c[i][j];
            //cout<<c[i][j]<<' ';
        }
        //cout<<endl;
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=i;j++) {
            long long cur=0;
            for (int k=1;k<=n;k++) {
                cur+=getsum(i,k,j,k);
                res=max(res,cur);
                if (cur<0) cur=0;
            }
        }
    }
    cout<<res;
}
