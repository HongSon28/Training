#include<bits/stdc++.h>
using namespace std;
const int N=100;
int h[N+5][N+5],d[N+5][N+5];
int m,n;
int inf=1e9;
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int res;
int main(){
    freopen("nuocdong.inp","r",stdin);
    freopen("nuocdong.out","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            cin>>h[i][j];
            d[i][j]=inf;
        }
    }
    for(int i=1;i<=m;i++) {
        d[i][1]=h[i][1];
        d[i][n]=h[i][n];
        pq.push({h[i][1], {i, 1}});
        pq.push({h[i][n], {i, n}});
    }
    for(int i=2;i<n;i++) {
        d[1][i]=h[1][i];
        d[m][i]=h[m][i];
        pq.push({h[1][i],{1, i}});
        pq.push({h[m][i],{m, i}});
    }
    while (!pq.empty()) {
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int du=pq.top().first;
        pq.pop();
        if (du!=d[x][y]) continue;
        for (int i=0;i<4;i++) {
            int tx=x+dx[i],ty=y+dy[i];
            if (tx<1||ty<1||tx>m||ty>n) continue;
            if (d[tx][ty]>max(d[x][y],h[ty][ty])) {
                d[tx][ty]=max(d[x][y],h[tx][ty]);
                pq.push({d[tx][ty],{tx,ty}});
            }
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=1;j<=n;j++) {
            if (d[i][j]>h[i][j])
                res+=d[i][j]-h[i][j];
        }
    }
    cout<<res;
}
