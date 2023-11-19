#include<bits/stdc++.h>
using namespace std;
const int N=1025;
int n;
int res;
int a[N][N],sum[N][N];
void rec(int n,int x1,int y1,int x2,int y2) {
    if (sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]==(1<<n)*(1<<n)) {
        res+=2;
        return;
    }
    if (sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]==0) {
        res+=2;
        return;
    }
    int xmid=(x1+x2)/2,ymid=(y1+y2)/2;
    res++;
    rec(n-1,x1,y1,xmid,ymid);
    rec(n-1,xmid+1,ymid+1,x2,y2);
    rec(n-1,x1,ymid+1,xmid,y2);
    rec(n-1,xmid+1,y1,x2,ymid);
}
int main() {
    freopen("IMAGE.INP","r",stdin);
    freopen("IMAGE.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=(1<<n);i++) {
        for (int j=1;j<=(1<<n);j++) {
            cin>>a[i][j];
            sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
        }
    }
    rec(n,1,1,(1<<n),(1<<n));
    cout<<res;
}
