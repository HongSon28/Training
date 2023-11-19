#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int m,n;
int a[N+5][N+5];
int par[N*N+5];
int cnt,mx,resi,resj,resk;
int findroot(int x) {
    if(par[x]<0) return x;
    return par[x]=findroot(par[x]);
}
void Union(int x,int y) {
    if ((x=findroot(x))==(y=findroot(y))) return;
    if (par[x]>par[y]) swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}
int conv(int x,int y) {
    return (x-1)*n+y;
}
int s,t;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main() {
    memset(par,-1,sizeof(par));
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            cin>>a[i][j];
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if ((a[i][j]>>0&1)==0) {//west
                s=findroot(conv(i,j));
                t=findroot(conv(i,j-1));
                if (j-1<1) continue;
                if (s!=t) Union(s,t);
                //cout<<i<<' '<<j<<' '<<i<<' '<<j-1<<endl;
            }
            if ((a[i][j]>>1&1)==0) {//north
                s=findroot(conv(i,j));
                t=findroot(conv(i-1,j));
                if (i-1<1) continue;
                if (s!=t) Union(s,t);
                //cout<<i<<' '<<j<<' '<<i-1<<' '<<j<<endl;
            }
            if ((a[i][j]>>2&1)==0) {//east
                s=findroot(conv(i,j));
                t=findroot(conv(i,j+1));
                if (j+1>n) continue;
                if (s!=t) Union(s,t);
                //cout<<i<<' '<<j<<' '<<i<<' '<<j+1<<endl;
            }
            if ((a[i][j]>>3&1)==0) {//south
                s=findroot(conv(i,j));
                t=findroot(conv(i+1,j));
                if (i+1>m) continue;
                if (s!=t) Union(s,t);
                //cout<<i<<' '<<j<<' '<<i+1<<' '<<j<<endl;
            }
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            int t=conv(i,j);
            if (par[t]<0) {
                cnt++;
                mx=max(mx,-par[t]);
            }
        }
    }
    cout<<cnt<<endl<<mx;
}
