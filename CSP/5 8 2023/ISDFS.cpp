#include<bits/stdc++.h>
using namespace std;
int t;
const int N=100;
int n,m,k;
bool used[N+5],vis[N+5];
bool isPath[N+5][N+5];
int x[N+5];
int main() {
    freopen("ISDFS.INP","r",stdin);
    freopen("ISDFS.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>t;
    while (t--) {
        vector<vector<int>>adj(N+5);
        bool flag=true;
        cin>>n>>m>>k;
        for (int i=1;i<=N;i++) vis[i]=used[i]=false;
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                isPath[i][j]=false;
        for (int i=1;i<=m;i++) {
            int u,v;
            cin>>u>>v;
            isPath[u][v]=isPath[v][u]=true;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (int i=1;i<=k;i++) {
            cin>>x[i];
            if (used[x[i]]) {
                flag=false;
                break;
            }
            used[x[i]]=true;
        }
        if (!flag) {
            cout<<"NO"<<'\n';
            continue;
        }
        vis[x[1]]=true;
        for (int i=2;i<=k;i++) {
            for (int j=i-1;j>=1;j--) {
                //cout<<i<<' '<<j<<endl;
                bool c1=false,c2=false;
                for (auto v:adj[x[j]]) {
                    if (vis[v]) continue;
                    if (v==x[i]) {
                        c1=true;
                        break;
                    } else c2=true;
                }
                if (c1) {
                    vis[x[i]]=true;
                    break;
                }
                if (!c1&&c2) {
                    flag=false;
                    break;
                }
            }
            if (!vis[x[i]]) {
                flag=false;
                break;
            }
        }
        if (!flag) {
            cout<<"NO"<<'\n';
            continue;
        }
        cout<<"YES"<<'\n';
    }
}
