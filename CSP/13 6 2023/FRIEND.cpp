#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4;
ll MX=1e16;
int n,m;
int ha,sa,hb,sb,res;
ll mn=1e18;
vector<vector<pair<ll,ll>>>adj(N+5);
ll d1[N+5],d2[N+5],d3[N+5],d4[N+5];
int trace1[N+5],trace2[N+5],trace3[N+5],trace4[N+5];
vector<int>va,vb;
void dijkstra(int s,ll *d,int *trace) {
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    for (int i=1;i<=n;i++) d[i]=MX;
    d[s]=0;
    q.push({d[s],s});
    while (!q.empty()) {
        pair<ll,ll>p=q.top();
        q.pop();
        int u=p.second;
        for (auto i:adj[u]){
            int v=i.first,w=i.second;
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                q.push(make_pair(d[v],v));
                trace[v]=u;
            }
        }
    }
}
int main() {
    freopen("FRIEND.INP","r",stdin);
    freopen("FRIEND.OUT","w",stdout);
    cin>>n>>m;
    cin>>ha>>sa>>hb>>sb;
    for (int i=1;i<=m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    dijkstra(ha,d1,trace1);
    dijkstra(hb,d2,trace2);
    dijkstra(sa,d3,trace3);
    dijkstra(sb,d4,trace4);
    trace1[ha]=-1;
    trace2[hb]=-1;
    ll shortest1=d1[sa],shortest2=d2[sb];
    while (trace1[sa]!=-1) {
        va.push_back(sa);
        sa=trace1[sa];
    }
    va.push_back(ha);
    reverse(va.begin(),va.end());
    while (trace2[sb]!=-1) {
        vb.push_back(sb);
        sb=trace2[sb];
    }
    vb.push_back(hb);
    reverse(vb.begin(),vb.end());
    for (int i=1;i<=n;i++) {
        if (d1[i]+d3[i]==shortest1&&d2[i]+d4[i]==shortest2&&d1[i]==d2[i]&&d1[i]<mn) {
            mn=d1[i];
            res=i;
        }
    }
    if (res!=0) {
        cout<<"YES"<<endl;
        cout<<shortest1<<endl;
        for (auto j:va) cout<<j<<' ';
        cout<<endl<<shortest2<<endl;
        for (auto j:vb) cout<<j<<' ';
        cout<<endl<<res<<endl<<d1[res];
    } else cout<<"NO";
}
