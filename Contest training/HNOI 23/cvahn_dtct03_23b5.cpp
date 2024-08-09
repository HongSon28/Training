#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5;
ll n,m,k,s,t;
ll res=1e18;
vector<vector<pair<ll,ll>>>adj(N+5);
ll d[N+5][10];
int main() {
    cin>>n>>m;
    s=1,t=n,k=1;
    for (int i=1;i<=m;i++) {
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=k;j++) {
            d[i][j]=1e18;
        }
    }
    d[s][0]=0;
    queue<pair<ll,ll>>q;
    q.push({s,0});
    while (!q.empty()) {
        pair<int,int>p=q.front();
        q.pop();
        for (auto i:adj[p.first]) {
            ll v=i.first,w=i.second;
            //cout<<v<<' '<<w<<endl;
            if(d[v][p.second]>d[p.first][p.second]+w) {
                d[v][p.second]=d[p.first][p.second]+w;
                //cout<<p.first<<' '<<p.second<<' '<<v<<' '<<p.second<<endl;
                q.push({v,p.second});
            }
            if (p.second<k&&d[v][p.second+1]>d[p.first][p.second]) {
                d[v][p.second+1]=d[p.first][p.second];
                //cout<<p.first<<' '<<p.second<<' '<<v<<' '<<p.second+1<<endl;
                q.push({v,p.second+1});
            }
        }
    }
    for (int i=0;i<=k;i++) res=min(res,d[t][i]);
    cout<<res;
}

