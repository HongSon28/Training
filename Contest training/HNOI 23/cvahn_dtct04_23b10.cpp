#include<bits/stdc++.h>
using namespace std;
const int N=1000,maxN=20000;
int n,x,y,m;
int d[maxN+5][maxN+5];
int inf=1e9,res=inf;
struct panel{
    int x1,x2,h;
    bool operator < (const panel &others) const {
        return h>others.h;
    }
};
struct dat{
    int x,y,id,d;
    bool operator < (const dat &others) const {
        return d>others.d;
    }
};
priority_queue<dat>pq;
panel a[N+5];
void dij() {
    while (!pq.empty()) {
        dat t=pq.top();
        if (t.d!=d[t.x][t.y]) continue;
        cout<<t.x<<' '<<t.y<<' '<<t.id<<' '<<t.d<<endl;
        if (t.id==n) {
            res=min(res,t.d+t.y);
            continue;
        }
        pq.pop();
        if (t.x>=a[t.id+1].x1&&t.x<=a[t.id+1].x2) {
            if (d[a[t.id+1].x1][a[t.id+1].h]>t.d+t.x-a[t.id+1].x1+t.y-a[t.id+1].h) {
                pq.push({a[t.id+1].x1,a[t.id+1].h,t.id+1,t.d+t.x-a[t.id+1].x1+t.y-a[t.id+1].h});
                d[a[t.id+1].x1][a[t.id+1].h]=t.d+t.x-a[t.id+1].x1+t.y-a[t.id+1].h;
            }
            if (d[a[t.id+1].x2][a[t.id+1].h]>t.d+a[t.id+1].x2-t.x+t.y-a[t.id+1].h) {
                pq.push({a[t.id+1].x2,a[t.id+1].h,t.id+1,t.d+a[t.id+1].x2-t.x+t.y-a[t.id+1].h});
                d[a[t.id+1].x2][a[t.id+1].h]=t.d+a[t.id+1].x2-t.x+t.y-a[t.id+1].h;
            }
        } else {
            if (d[t.x][a[t.id+1].h]>t.d+t.y-a[t.id+1].h) {
                pq.push({t.x,a[t.id+1].h,t.id+1,t.d+t.y-a[t.id+1].h});
                d[t.x][a[t.id+1].h]=t.d+t.y-a[t.id+1].h;
            }
        }
    }
}
int main() {
    freopen("FALL.INP","r",stdin);
    freopen("FALL.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>x>>y>>m;
    for (int i=1;i<=n;i++) cin>>a[i].x1>>a[i].x2>>a[i].h;
    sort(a+1,a+1+n);
    for (int i=0;i<=maxN;i++)
        for (int j=0;j<=maxN;j++)
            d[i][j]=inf;
    for (int i=1;i<=n;i++) {
        if (a[i].h>y) continue;
        if (x>=a[i].x1&&x<=a[i].x2) {
            if (d[a[i].x1][a[i].h]>x-a[i].x1+y-a[i].h) {
                pq.push({a[i].x1,a[i].h,i,x-a[i].x1+y-a[i].h});
                d[a[i].x1][a[i].h]=x-a[i].x1+y-a[i].h;
            }
            if (d[a[i].x2][a[i].h]>a[i].x2-x+y-a[i].h) {
                pq.push({a[i].x2,a[i].h,i,a[i].x2-x+y-a[i].h});
                d[a[i].x2][a[i].h]=a[i].x2-x+y-a[i].h;
            }
        } else {
            if (d[x][a[i].h]>y-a[i].h) {
                pq.push({x,a[i].h,i,y-a[i].h});
                d[x][a[i].h]=y-a[i].h;
            }
        }
        if (a[i].h!=a[i+1].h) break;
    }
    dij();
    cout<<res;
}
