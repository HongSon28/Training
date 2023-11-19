#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2000;
ll m,n;
ll d[N+5][N+5];
ll below[N+5][N+5],door[N+5][N+5];
ll inf=1e18;
struct dat{
    ll x,y,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PRISON.INP","r",stdin);
    freopen("PRISON.OUT","w",stdout);
    cin>>m>>n;
    for (ll i=1;i<=m*2;i++) {
        if (i%2==1)
            for (ll j=1;j<=n;j++) cin>>below[i/2+1][j];
        else
            for (ll j=1;j<n;j++) cin>>door[i/2][j];
    }
    for (ll i=1;i<=m;i++)
        for (ll j=1;j<=n;j++)
            d[i][j]=inf;
    for (ll i=1;i<=n;i++) {
        pq.push({0,i,0});
        d[0][i]=0;
    }
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        if (t.d!=d[t.x][t.y]) continue;
        if (t.y==1) {
            if (d[t.x][t.y]+door[t.x][t.y]<d[t.x][t.y+1]) {
                d[t.x][t.y+1]=d[t.x][t.y]+door[t.x][t.y];
                pq.push({t.x,t.y+1,d[t.x][t.y+1]});
            }
        } else if (t.y==n) {
            if (d[t.x][t.y]+door[t.x][t.y-1]<d[t.x][t.y-1]) {
                d[t.x][t.y-1]=d[t.x][t.y]+door[t.x][t.y-1];
                pq.push({t.x,t.y-1,d[t.x][t.y-1]});
            }
        } else {
            if (d[t.x][t.y]+door[t.x][t.y]<d[t.x][t.y+1]) {
                d[t.x][t.y+1]=d[t.x][t.y]+door[t.x][t.y];
                pq.push({t.x,t.y+1,d[t.x][t.y+1]});
            }
            if (d[t.x][t.y]+door[t.x][t.y-1]<d[t.x][t.y-1]) {
                d[t.x][t.y-1]=d[t.x][t.y]+door[t.x][t.y-1];
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

