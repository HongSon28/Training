#include<bits/stdc++.h>
using namespace std;
const int maxM=2222;
const int maxN=10;
int m,n;
int d[maxM+5][maxN+5];
int below[maxM+5][maxN+5],door[maxM+5];
int inf=1e9;
struct dat{
    int x,y,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
int main() {
    cin>>m>>n;
    for (int i=1;i<=m*2;i++) {
        if (i%2==1)
            for (int j=1;j<=n;j++) cin>>below[i/2+1][j];
        else
            cin>>door[i/2];
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            d[i][j]=inf;
    for (int i=1;i<=n;i++) {
        pq.push({1,i,below[1][i]});
        d[1][i]=below[1][i];
    }
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        if (t.d!=d[t.x][t.y]) continue;
        if (t.y==1) {
            if (d[t.x][t.y]+door[t.x]<d[t.x][t.y+1]) {
                d[t.x][t.y+1]=d[t.x][t.y]+door[t.x];
                pq.push({t.x,t.y+1,d[t.x][t.y+1]});
            }
        } else if (t.y==n) {
            if (d[t.x][t.y]+door[t.x]<d[t.x][t.y-1]) {
                d[t.x][t.y-1]=d[t.x][t.y]+door[t.x];
                pq.push({t.x,t.y-1,d[t.x][t.y-1]});
            }
        } else {
            if (d[t.x][t.y]+door[t.x]<d[t.x][t.y+1]) {
                d[t.x][t.y+1]=d[t.x][t.y]+door[t.x];
                pq.push({t.x,t.y+1,d[t.x][t.y+1]});
            }
            if (d[t.x][t.y]+door[t.x]<d[t.x][t.y-1]) {
                d[t.x][t.y-1]=d[t.x][t.y]+door[t.x];
                pq.push({t.x,t.y-1,d[t.x][t.y-1]});
            }
        }
        if (t.x!=0) {
            if (d[t.x][t.y]+below[t.x][t.y]<d[t.x-1][t.y]) {
                d[t.x-1][t.y]=d[t.x][t.y]+below[t.x][t.y];
                pq.push({t.x-1,t.y,d[t.x-1][t.y]});
            }
        }
        if (t.x!=m) {
            if (d[t.x][t.y]+below[t.x+1][t.y]<d[t.x+1][t.y]) {
                d[t.x+1][t.y]=d[t.x][t.y]+below[t.x+1][t.y];
                pq.push({t.x+1,t.y,d[t.x+1][t.y]});
            }
        }
    }
    cout<<d[m][n];
}
