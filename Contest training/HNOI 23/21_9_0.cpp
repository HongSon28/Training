#include<bits/stdc++.h>
using namespace std;
const int N=50;
int r,s;
char c[N+5][N+5];
int ans,mx;
int dx[]={0,0,1,1,1,-1,-1,-1};
int dy[]={1,-1,-1,0,1,-1,0,1};
int cnt(int i,int j) {
    int res=0;
    for (int k=0;k<8;k++){
        int u=i+dx[k],v=j+dy[k];
        if (c[u][v]=='o') res++;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>r>>s;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=s;j++)
            cin>>c[i][j];
    for (int i=1;i<=r;i++)
        for (int j=1;j<=s;j++)
            if (c[i][j]=='o') ans+=cnt(i,j);
    ans/=2;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=s;j++)
            if (c[i][j]=='.') mx=max(mx,cnt(i,j));
    ans+=mx;
    cout<<ans;
}
