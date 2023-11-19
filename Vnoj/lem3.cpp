#include<bits/stdc++.h>
using namespace std;
const int N=16;
int n;
int d[(1<<(N+5))+5][N+5];
int c[N+5][N+5];
int inf=1e9,res=inf;
struct dat{
    int mask,u,d;
    bool operator < (const dat &other) const {
        return d>other.d;
    }
};
priority_queue<dat>pq;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            cin>>c[i][j];
    for (int i=0;i<(1<<(N+1));i++)
        for (int j=0;j<=N;j++)
            d[i][j]=inf;
    for (int i=1;i<=n;i++) {
        int mask=(1<<i);
        d[mask][i]=0;
        pq.push({mask,i,0});
    }
    while (!pq.empty()) {
        dat t=pq.top();
        pq.pop();
        int mask=t.mask,u=t.u,du=t.d;
        if (du!=t.d) continue;
        for (int v=1;v<=n;v++) {
            if ((mask>>v)&1) continue;
            int bit=mask|(1<<v);
            //cout<<u<<' '<<v<<' '<<mask<<' '<<bit<<endl;
            if (d[bit][v]>du+c[u][v]) {
                d[bit][v]=du+c[u][v];
                pq.push({bit,v,d[bit][v]});
            }
        }
    }
    int mask=0;
    for (int i=1;i<=n;i++) mask|=(1<<i);
    for (int i=1;i<=n;i++) res=min(res,d[mask][i]);
    cout<<res;
}
